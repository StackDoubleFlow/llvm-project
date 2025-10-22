//===-- URCLTargetMachine.cpp - Define TargetMachine for URCL -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the URCL specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#include "URCLTargetMachine.h"

#include "MCTargetDesc/URCLMCTargetDesc.h"
#include "TargetInfo/URCLTargetInfo.h"
#include "URCL.h"
#include "URCLMachineFunctionInfo.h"
#include "URCLTargetTransformInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

#include <optional>

namespace llvm {

static Reloc::Model getEffectiveRelocModel(std::optional<Reloc::Model> RM) {
  return RM.value_or(Reloc::Static);
}

URCLTargetMachine::URCLTargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     std::optional<Reloc::Model> RM,
                                     std::optional<CodeModel::Model> CM,
                                     CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, TT.computeDataLayout(), TT, CPU, FS, Options,
                               getEffectiveRelocModel(RM),
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      SubTarget(TT, std::string(CPU), std::string(FS), *this) {
  initAsmInfo();
}

namespace {
/// URCL Code Generator Pass Configuration Options.
class URCLPassConfig : public TargetPassConfig {
public:
  URCLPassConfig(URCLTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {
    EnableLoopTermFold = true;
  }

  URCLTargetMachine &getURCLTargetMachine() const {
    return getTM<URCLTargetMachine>();
  }

  void addIRPasses() override;
  bool addInstSelector() override;
  void addPreSched2() override;
  void addPreEmitPass() override;
};
} // namespace

TargetPassConfig *URCLTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new URCLPassConfig(*this, PM);
}

void URCLPassConfig::addIRPasses() { TargetPassConfig::addIRPasses(); }

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void LLVMInitializeURCLTarget() {
  // Register the target.
  RegisterTargetMachine<URCLTargetMachine> X(getTheURCLTarget());

  auto &PR = *PassRegistry::getPassRegistry();
  initializeURCLAsmPrinterPass(PR);
  initializeURCLDAGToDAGISelLegacyPass(PR);
}

const URCLSubtarget *URCLTargetMachine::getSubtargetImpl() const {
  return &SubTarget;
}

const URCLSubtarget *
URCLTargetMachine::getSubtargetImpl(const Function &) const {
  return &SubTarget;
}

TargetTransformInfo
URCLTargetMachine::getTargetTransformInfo(const Function &F) const {
  return TargetTransformInfo(std::make_unique<URCLTTIImpl>(this, F));
}

MachineFunctionInfo *URCLTargetMachine::createMachineFunctionInfo(
    BumpPtrAllocator &Allocator, const Function &F,
    const TargetSubtargetInfo *STI) const {
  return URCLMachineFunctionInfo::create<URCLMachineFunctionInfo>(Allocator, F,
                                                                  STI);
}

//===----------------------------------------------------------------------===//
// Pass Pipeline Configuration
//===----------------------------------------------------------------------===//

bool URCLPassConfig::addInstSelector() {
  // Install an instruction selector.
  addPass(createURCLISelDag(getURCLTargetMachine(), getOptLevel()));
  // Create the frame analyzer pass used by the PEI pass.

  return false;
}

void URCLPassConfig::addPreSched2() {}

void URCLPassConfig::addPreEmitPass() {
  // Must run branch selection immediately preceding the asm printer.
  addPass(&BranchRelaxationPassID);
}

} // end of namespace llvm
