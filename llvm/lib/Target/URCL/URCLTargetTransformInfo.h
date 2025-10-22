//===- URCLTargetTransformInfo.h - URCL specific TTI --------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
/// \file
/// This file defines a TargetTransformInfoImplBase conforming object specific
/// to the URCL target machine. It uses the target's detailed information to
/// provide more precise answers to certain TTI queries, while letting the
/// target independent and default TTI implementations handle the rest.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_URCL_URCLTARGETTRANSFORMINFO_H
#define LLVM_LIB_TARGET_URCL_URCLTARGETTRANSFORMINFO_H

#include "URCLSubtarget.h"
#include "URCLTargetMachine.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/CodeGen/BasicTTIImpl.h"
#include "llvm/IR/Function.h"
#include <optional>

namespace llvm {

class URCLTTIImpl final : public BasicTTIImplBase<URCLTTIImpl> {
  using BaseT = BasicTTIImplBase<URCLTTIImpl>;
  using TTI = TargetTransformInfo;

  friend BaseT;

  const URCLSubtarget *ST;
  const URCLTargetLowering *TLI;

  const URCLSubtarget *getST() const { return ST; }
  const URCLTargetLowering *getTLI() const { return TLI; }

public:
  explicit URCLTTIImpl(const URCLTargetMachine *TM, const Function &F)
      : BaseT(TM, F.getDataLayout()), ST(TM->getSubtargetImpl(F)),
        TLI(ST->getTargetLowering()) {}
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_URCL_URCLTARGETTRANSFORMINFO_H
