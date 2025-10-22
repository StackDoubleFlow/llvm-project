//===-- URCLInstPrinter.cpp - Convert URCL MCInst to assembly syntax --------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints an URCL MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#include "URCLInstPrinter.h"

#include "MCTargetDesc/URCLMCTargetDesc.h"

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrDesc.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/Support/ErrorHandling.h"

#include <cstring>

#define DEBUG_TYPE "asm-printer"

namespace llvm {

// Include the auto-generated portion of the assembly writer.
#define PRINT_ALIAS_INSTR
#include "URCLGenAsmWriter.inc"

void URCLInstPrinter::printInst(const MCInst *MI, uint64_t Address,
                               StringRef Annot, const MCSubtargetInfo &STI,
                               raw_ostream &O) {
  // TODO
}

const char *URCLInstPrinter::getPrettyRegisterName(MCRegister Reg,
                                                  MCRegisterInfo const &MRI) {
  // TODO
  return "TODO";
}

void URCLInstPrinter::printOperand(const MCInst *MI, unsigned OpNo,
                                  raw_ostream &O) {
  // TODO
}

} // end of namespace llvm
