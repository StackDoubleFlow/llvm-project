//===-- URCLTargetStreamer.cpp - URCL Target Streamer Methods ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides URCL specific target streamer methods.
//
//===----------------------------------------------------------------------===//

#include "URCLTargetStreamer.h"

#include "llvm/MC/MCContext.h"

namespace llvm {

URCLTargetStreamer::URCLTargetStreamer(MCStreamer &S) : MCTargetStreamer(S) {}

URCLTargetAsmStreamer::URCLTargetAsmStreamer(MCStreamer &S)
    : URCLTargetStreamer(S) {}

} // end namespace llvm
