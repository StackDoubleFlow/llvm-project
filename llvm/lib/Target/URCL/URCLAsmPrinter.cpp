//===-- URCLAsmPrinter.cpp - URCL LLVM assembly writer ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to GAS-format URCL assembly language.
//
//===----------------------------------------------------------------------===//

#include "URCL.h"
#include "URCLMCInstLower.h"
#include "URCLSubtarget.h"
#include "URCLTargetMachine.h"
#include "MCTargetDesc/URCLInstPrinter.h"
#include "MCTargetDesc/URCLMCAsmInfo.h"
#include "TargetInfo/URCLTargetInfo.h"

#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/Mangler.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCSectionELF.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetLoweringObjectFile.h"

#define DEBUG_TYPE "urcl-asm-printer"

using namespace llvm;

namespace {

/// An URCL assembly code printer.
class URCLAsmPrinter : public AsmPrinter {
public:
  URCLAsmPrinter(TargetMachine &TM, std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer), ID), MRI(*TM.getMCRegisterInfo()) {}

  StringRef getPassName() const override { return "URCL Assembly Printer"; }

  void emitInstruction(const MachineInstr *MI) override;

  static char ID;

private:
  const MCRegisterInfo &MRI;
};

} // namespace
void URCLAsmPrinter::emitInstruction(const MachineInstr *MI) {
  URCLMCInstLower MCInstLowering(&OutContext, *this);

  MCInst I;
  MCInstLowering.Lower(MI, I);
  EmitToStreamer(*OutStreamer, I);
}

char URCLAsmPrinter::ID = 0;

INITIALIZE_PASS(URCLAsmPrinter, "urcl-asm-printer", "URCL Assembly Printer", false,
                false)

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializeURCLAsmPrinter() {
  llvm::RegisterAsmPrinter<URCLAsmPrinter> X(getTheURCLTarget());
}
