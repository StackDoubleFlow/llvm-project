//===-- URCLTargetMachine.h - Define TargetMachine for URCL -------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the URCL specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_URCL_TARGET_MACHINE_H
#define LLVM_URCL_TARGET_MACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include "llvm/IR/DataLayout.h"

#include "URCLFrameLowering.h"
#include "URCLISelLowering.h"
#include "URCLInstrInfo.h"
#include "URCLSelectionDAGInfo.h"
#include "URCLSubtarget.h"

#include <optional>

namespace llvm {

/// A generic URCL implementation.
class URCLTargetMachine : public CodeGenTargetMachineImpl {
public:
  URCLTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const URCLSubtarget *getSubtargetImpl() const;
  const URCLSubtarget *getSubtargetImpl(const Function &) const override;

  TargetLoweringObjectFile *getObjFileLowering() const override {
    return this->TLOF.get();
  }

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;

  MachineFunctionInfo *
  createMachineFunctionInfo(BumpPtrAllocator &Allocator, const Function &F,
                            const TargetSubtargetInfo *STI) const override;

  TargetTransformInfo getTargetTransformInfo(const Function &F) const override;

  bool isNoopAddrSpaceCast(unsigned SrcAs, unsigned DestAs) const override {
    // While URCL has different address spaces, they are all represented by
    // 16-bit pointers that can be freely casted between (of course, a pointer
    // must be cast back to its original address space to be dereferenceable).
    // To be safe, also check the pointer size in case we implement __memx
    // pointers.
    return getPointerSize(SrcAs) == getPointerSize(DestAs);
  }

private:
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  URCLSubtarget SubTarget;
};

} // end namespace llvm

#endif // LLVM_URCL_TARGET_MACHINE_H
