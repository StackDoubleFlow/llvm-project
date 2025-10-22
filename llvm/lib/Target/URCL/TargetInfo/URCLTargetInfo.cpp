//===-- URCLTargetInfo.cpp - URCL Target Implementation
//---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "TargetInfo/URCLTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"
namespace llvm {
Target &getTheURCLTarget() {
  static Target TheURCLTarget;
  return TheURCLTarget;
}
} // namespace llvm

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializeURCLTargetInfo() {
  llvm::RegisterTarget<llvm::Triple::urcl> X(
      llvm::getTheURCLTarget(), "urcl",
      "Universal Reduced (or Redstone) Computer Language", "URCL");
}
