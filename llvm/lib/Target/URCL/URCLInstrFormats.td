//===-- URCLInstrInfo.td - URCL Instruction Formats ----------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// URCL Instruction Format Definitions.
//
//===----------------------------------------------------------------------===//

// A generic URCL instruction.
class URCLInst<dag outs, dag ins>
    : Instruction {
  let Namespace = "URCL";

  dag OutOperandList = outs;
  dag InOperandList = ins;
  let Pattern = [];
  field bits<32> Inst;
}

class URCL_r_rr<string name, dag outs, dag ins>
    : URCLInst<outs, ins>
{
  bits<8> rs1;
  bits<8> rs2;
  bits<8> rd;

  let Size = 4;
  let AsmString = !strconcat(name, "\t$rd, $rs1, $rs2");
  let Inst{7-0} = rd;
  let Inst{15-8} = rs1;
  let Inst{23-16} = rs2;
}

