//===-- URCLInstrInfo.h - URCL Instruction Information ------------*- C++ -*-===//
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

#ifndef LLVM_URCL_INSTR_INFO_H
#define LLVM_URCL_INSTR_INFO_H

#include "llvm/CodeGen/TargetInstrInfo.h"

#include "URCLRegisterInfo.h"

#define GET_INSTRINFO_HEADER
#include "URCLGenInstrInfo.inc"
#undef GET_INSTRINFO_HEADER

namespace llvm {

class URCLSubtarget;

/// Utilities related to the URCL instruction set.
class URCLInstrInfo : public URCLGenInstrInfo {
public:
  explicit URCLInstrInfo(const URCLSubtarget &STI);

  const URCLRegisterInfo &getRegisterInfo() const { return RI; }

private:
  const URCLRegisterInfo RI;

protected:
  const URCLSubtarget &STI;
};

} // end namespace llvm

#endif // LLVM_URCL_INSTR_INFO_H
