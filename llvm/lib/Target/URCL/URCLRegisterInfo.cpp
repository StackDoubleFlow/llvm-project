//===-- URCLRegisterInfo.cpp - URCL Register Information
//--------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the URCL implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "URCLRegisterInfo.h"

#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

#include "MCTargetDesc/URCLMCTargetDesc.h"
#include "URCL.h"
#include "URCLInstrInfo.h"
#include "URCLMachineFunctionInfo.h"
#include "URCLTargetMachine.h"

#define GET_REGINFO_TARGET_DESC
#include "URCLGenRegisterInfo.inc"

namespace llvm {

URCLRegisterInfo::URCLRegisterInfo() : URCLGenRegisterInfo(0) {}

const MCPhysReg *
URCLRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  // TODO
  return nullptr;
}

BitVector URCLRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  // TODO
  return BitVector();
}

bool URCLRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                           int SPAdj, unsigned FIOperandNum,
                                           RegScavenger *RS) const {
  // TODO
  return false;
}

Register URCLRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  // TODO
  return 0;
}

} // end of namespace llvm
