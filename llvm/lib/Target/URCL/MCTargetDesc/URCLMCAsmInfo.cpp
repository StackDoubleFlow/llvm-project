//===-- URCLMCAsmInfo.cpp - URCL asm properties -----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the URCLMCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "URCLMCAsmInfo.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCValue.h"
#include "llvm/TargetParser/Triple.h"

using namespace llvm;

URCLMCAsmInfo::URCLMCAsmInfo(const Triple &TT, const MCTargetOptions &Options) {
  CodePointerSize = 2;
  CalleeSaveStackSlotSize = 2;
  CommentString = ";";
  SeparatorString = "$";
  UsesELFSectionDirectiveForBSS = true;
  SupportsDebugInformation = true;
}
