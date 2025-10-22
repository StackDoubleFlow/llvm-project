//===-- URCLISelLowering.h - URCL DAG Lowering Interface ----------*- C++ -*-===//
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

#ifndef LLVM_URCL_ISEL_LOWERING_H
#define LLVM_URCL_ISEL_LOWERING_H

#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class URCLSubtarget;
class URCLTargetMachine;

/// Performs target lowering for the URCL.
class URCLTargetLowering : public TargetLowering {
public:
  explicit URCLTargetLowering(const URCLTargetMachine &TM,
                             const URCLSubtarget &STI);

public:
  private:
protected:
  const URCLSubtarget &Subtarget;

private:
};

} // end namespace llvm

#endif // LLVM_URCL_ISEL_LOWERING_H
