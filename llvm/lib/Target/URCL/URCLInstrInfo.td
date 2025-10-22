//===-- URCLInstrInfo.td - URCL Instruction defs -------------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the URCL instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

include "URCLInstrFormats.td"

def ADD : URCL_r_rr<"ADD", (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2)>;