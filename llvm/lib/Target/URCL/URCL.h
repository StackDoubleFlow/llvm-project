//===-- URCL.h - Top-level interface for URCL representation ------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in the LLVM
// URCL back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_URCL_H
#define LLVM_URCL_H

#include "llvm/CodeGen/SelectionDAGNodes.h"
#include "llvm/Pass.h"
#include "llvm/PassRegistry.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class URCLTargetMachine;
class FunctionPass;
class PassRegistry;

FunctionPass *createURCLISelDag(URCLTargetMachine &TM, CodeGenOptLevel OptLevel);

void initializeURCLAsmPrinterPass(PassRegistry &);
void initializeURCLDAGToDAGISelLegacyPass(PassRegistry &);
void initializeURCLExpandPseudoPass(PassRegistry &);

/// Contains the URCL backend.
namespace URCL {

} // end of namespace URCL

} // end namespace llvm

#endif // LLVM_URCL_H
