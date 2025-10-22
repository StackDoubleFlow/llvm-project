//===-- URCLSubtarget.cpp - URCL Subtarget Information ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the URCL specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "URCLSubtarget.h"

#include "llvm/BinaryFormat/ELF.h"
#include "llvm/MC/TargetRegistry.h"

#include "URCL.h"
#include "URCLTargetMachine.h"

#define DEBUG_TYPE "urcl-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "URCLGenSubtargetInfo.inc"

namespace llvm {

URCLSubtarget::URCLSubtarget(const Triple &TT, const std::string &CPU,
                           const std::string &FS, const URCLTargetMachine &TM)
    : URCLGenSubtargetInfo(TT, CPU, /*TuneCPU*/ CPU, FS), InstrInfo(*this),
      TLInfo(TM, initializeSubtargetDependencies(CPU, FS, TM)) {
  // Parse features string.
  ParseSubtargetFeatures(CPU, /*TuneCPU*/ CPU, FS);
}

URCLSubtarget &
URCLSubtarget::initializeSubtargetDependencies(StringRef CPU, StringRef FS,
                                              const TargetMachine &TM) {
  // Parse features string.
  ParseSubtargetFeatures(CPU, /*TuneCPU*/ CPU, FS);
  return *this;
}

} // end of namespace llvm
