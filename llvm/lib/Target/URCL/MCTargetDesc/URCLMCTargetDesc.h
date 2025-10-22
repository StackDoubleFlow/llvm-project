//===-- URCLMCTargetDesc.h - URCL Target Descriptions -------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides URCL specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_URCL_MCTARGET_DESC_H
#define LLVM_URCL_MCTARGET_DESC_H

#include "llvm/Support/DataTypes.h"

#include <memory>

namespace llvm {

class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCInstrInfo *createURCLMCInstrInfo();

/// Creates a machine code emitter for URCL.
MCCodeEmitter *createURCLMCCodeEmitter(const MCInstrInfo &MCII,
                                      MCContext &Ctx);

/// Creates an assembly backend for URCL.
MCAsmBackend *createURCLAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const llvm::MCTargetOptions &TO);

/// Creates an ELF object writer for URCL.
std::unique_ptr<MCObjectTargetWriter> createURCLELFObjectWriter(uint8_t OSABI);

} // end namespace llvm

#define GET_REGINFO_ENUM
#include "URCLGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#define GET_INSTRINFO_MC_HELPER_DECLS
#include "URCLGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "URCLGenSubtargetInfo.inc"

#endif // LLVM_URCL_MCTARGET_DESC_H
