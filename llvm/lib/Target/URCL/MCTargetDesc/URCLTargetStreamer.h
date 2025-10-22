//===-- URCLTargetStreamer.h - URCL Target Streamer --------------*- C++ -*--===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_URCL_TARGET_STREAMER_H
#define LLVM_URCL_TARGET_STREAMER_H

#include "llvm/MC/MCELFStreamer.h"

namespace llvm {
class MCStreamer;

/// A generic URCL target output stream.
class URCLTargetStreamer : public MCTargetStreamer {
public:
  explicit URCLTargetStreamer(MCStreamer &S);
};

/// A target streamer for textual URCL assembly code.
class URCLTargetAsmStreamer : public URCLTargetStreamer {
public:
  explicit URCLTargetAsmStreamer(MCStreamer &S);
};

} // end namespace llvm

#endif // LLVM_URCL_TARGET_STREAMER_H
