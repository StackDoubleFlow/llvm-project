//===-- URCLInstrInfo.cpp - URCL Instruction Information --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the URCL implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#include "URCLInstrInfo.h"

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/MCContext.h"
#include "llvm/Support/ErrorHandling.h"

#include "URCL.h"
#include "URCLMachineFunctionInfo.h"
#include "URCLRegisterInfo.h"
#include "URCLTargetMachine.h"
#include "MCTargetDesc/URCLMCTargetDesc.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "URCLGenInstrInfo.inc"

namespace llvm {

// TODO: ADJCALLSTACKUP and ADJCALLSTACKDOWN
URCLInstrInfo::URCLInstrInfo(const URCLSubtarget &STI)
    : URCLGenInstrInfo(STI, URCL::ADD, URCL::ADD), RI(),
      STI(STI) {}

} // end of namespace llvm
