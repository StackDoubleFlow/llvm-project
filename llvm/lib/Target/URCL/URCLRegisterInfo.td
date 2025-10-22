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

// 8-bit General purpose register definition.
class URCLReg<bits<16> num, string name, list<Register> subregs = [],
             list<string> altNames = []> : RegisterWithSubRegs<name, subregs> {
  field bits<16> Num = num;

  let HWEncoding = num;
  let Namespace = "URCL";
  let SubRegs = subregs;
  let AltNames = altNames;
}

// Subregister indices.
let Namespace = "URCL" in {
  def sub_lo : SubRegIndex<8>;
  def sub_hi : SubRegIndex<8, 8>;
}

let Namespace = "URCL" in { def ptr : RegAltNameIndex; }

//===----------------------------------------------------------------------===//
//  8-bit general purpose registers
//===----------------------------------------------------------------------===//

def R0 : URCLReg<0, "R0">, DwarfRegNum<[0]>;
def R1 : URCLReg<1, "R1">, DwarfRegNum<[1]>;
def R2 : URCLReg<2, "R2">, DwarfRegNum<[2]>;
def R3 : URCLReg<3, "R3">, DwarfRegNum<[3]>;
def R4 : URCLReg<4, "R4">, DwarfRegNum<[4]>;
def R5 : URCLReg<5, "R5">, DwarfRegNum<[5]>;
def R6 : URCLReg<6, "R6">, DwarfRegNum<[6]>;
def R7 : URCLReg<7, "R7">, DwarfRegNum<[7]>;
def R8 : URCLReg<8, "R8">, DwarfRegNum<[8]>;
def R9 : URCLReg<9, "R9">, DwarfRegNum<[9]>;
def R10 : URCLReg<10, "R10">, DwarfRegNum<[10]>;
def R11 : URCLReg<11, "R11">, DwarfRegNum<[11]>;
def R12 : URCLReg<12, "R12">, DwarfRegNum<[12]>;
def R13 : URCLReg<13, "R13">, DwarfRegNum<[13]>;
def R14 : URCLReg<14, "R14">, DwarfRegNum<[14]>;
def R15 : URCLReg<15, "R15">, DwarfRegNum<[15]>;
def R16 : URCLReg<16, "R16">, DwarfRegNum<[16]>;
def R17 : URCLReg<17, "R17">, DwarfRegNum<[17]>;
def R18 : URCLReg<18, "R18">, DwarfRegNum<[18]>;
def R19 : URCLReg<19, "R19">, DwarfRegNum<[19]>;
def R20 : URCLReg<20, "R20">, DwarfRegNum<[20]>;
def R21 : URCLReg<21, "R21">, DwarfRegNum<[21]>;
def R22 : URCLReg<22, "R22">, DwarfRegNum<[22]>;
def R23 : URCLReg<23, "R23">, DwarfRegNum<[23]>;
def R24 : URCLReg<24, "R24">, DwarfRegNum<[24]>;
def R25 : URCLReg<25, "R25">, DwarfRegNum<[25]>;
def R26 : URCLReg<26, "R26">, DwarfRegNum<[26]>;
def R27 : URCLReg<27, "R27">, DwarfRegNum<[27]>;
def R28 : URCLReg<28, "R28">, DwarfRegNum<[28]>;
def R29 : URCLReg<29, "R29">, DwarfRegNum<[29]>;
def R30 : URCLReg<30, "R30">, DwarfRegNum<[30]>;
def R31 : URCLReg<31, "R31">, DwarfRegNum<[31]>;

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
