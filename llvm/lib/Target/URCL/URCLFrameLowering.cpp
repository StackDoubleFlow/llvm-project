//===-- URCLFrameLowering.cpp - URCL Frame Information
//----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the URCL implementation of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#include "URCLFrameLowering.h"

#include "MCTargetDesc/URCLMCTargetDesc.h"
#include "URCL.h"
#include "URCLInstrInfo.h"
#include "URCLMachineFunctionInfo.h"
#include "URCLTargetMachine.h"

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

namespace llvm {

URCLFrameLowering::URCLFrameLowering()
    : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(1), -2) {}

void URCLFrameLowering::emitPrologue(MachineFunction &MF,
                                     MachineBasicBlock &MBB) const {}

void URCLFrameLowering::emitEpilogue(MachineFunction &MF,
                                     MachineBasicBlock &MBB) const {}

bool URCLFrameLowering::hasFPImpl(const MachineFunction &MF) const {
  return false;
}

} // end of namespace llvm
