//===-- URCLISelLowering.cpp - URCL DAG Lowering Implementation -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that URCL uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#include "URCLISelLowering.h"

#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/ErrorHandling.h"

#include "URCL.h"
#include "URCLMachineFunctionInfo.h"
#include "URCLSubtarget.h"
#include "URCLTargetMachine.h"
#include "MCTargetDesc/URCLMCTargetDesc.h"

namespace llvm {

URCLTargetLowering::URCLTargetLowering(const URCLTargetMachine &TM,
                                     const URCLSubtarget &STI)
    : TargetLowering(TM), Subtarget(STI) {
  // Set up the register classes.
  addRegisterClass(MVT::i8, &URCL::GPRRegClass);

  // Compute derived properties from the register classes.
  computeRegisterProperties(Subtarget.getRegisterInfo());
}

} // end of namespace llvm
