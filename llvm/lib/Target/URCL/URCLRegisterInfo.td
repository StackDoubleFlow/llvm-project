//===-- URCLRegisterInfo.td - URCL Register defs -------------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the URCL register file
//===----------------------------------------------------------------------===//

// General purpose register definition.
class URCLReg<bits<16> num, string name, list<Register> subregs = [],
             list<string> altNames = []> : RegisterWithSubRegs<name, subregs> {
  field bits<16> Num = num;

  let HWEncoding = num;
  let Namespace = "URCL";
  let AltNames = altNames;
}

let Namespace = "URCL" in { def ptr : RegAltNameIndex; }

//===----------------------------------------------------------------------===//
// general purpose registers
//===----------------------------------------------------------------------===//

foreach Index = 0-127 in {
  def R#Index : URCLReg<Index, "R0">, DwarfRegNum<[Index]>;
}

//===----------------------------------------------------------------------===//
// Register Classes
//===----------------------------------------------------------------------===//

// Main 8-bit register class.
def GPR : RegisterClass<"URCL", [i8], 8,
                         (// Return value and argument registers.
                          add R24, R25, R18, R19, R20, R21, R22, R23,
                          // Scratch registers.
                          R30, R31, R26, R27,
                          // Callee saved registers.
                          R28, R29, R17, R16, R15, R14, R13, R12, R11, R10,
                          R9, R8, R7, R6, R5, R4, R3, R2, R1)>;
