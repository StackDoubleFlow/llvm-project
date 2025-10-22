//===-- URCLMCTargetDesc.cpp - URCL Target Descriptions ---------------------===//
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

#include "URCLMCTargetDesc.h"
#include "URCLInstPrinter.h"
#include "URCLMCAsmInfo.h"
#include "URCLTargetStreamer.h"
#include "TargetInfo/URCLTargetInfo.h"

#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

#define GET_INSTRINFO_MC_DESC
#define ENABLE_INSTR_PREDICATE_VERIFIER
#include "URCLGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "URCLGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "URCLGenRegisterInfo.inc"

using namespace llvm;

MCInstrInfo *llvm::createURCLMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitURCLMCInstrInfo(X);

  return X;
}

static MCRegisterInfo *createURCLMCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitURCLMCRegisterInfo(X, 0);

  return X;
}

static MCSubtargetInfo *createURCLMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  return createURCLMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCInstPrinter *createURCLMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  if (SyntaxVariant == 0) {
    return new URCLInstPrinter(MAI, MII, MRI);
  }

  return nullptr;
}

// static MCStreamer *createMCStreamer(const Triple &T, MCContext &Context,
//                                     std::unique_ptr<MCAsmBackend> &&MAB,
//                                     std::unique_ptr<MCObjectWriter> &&OW,
//                                     std::unique_ptr<MCCodeEmitter> &&Emitter) {
//   return createELFStreamer(Context, std::move(MAB), std::move(OW),
//                            std::move(Emitter));
// }

// static MCTargetStreamer *
// createURCLObjectTargetStreamer(MCStreamer &S, const MCSubtargetInfo &STI) {
//   return new URCLELFStreamer(S, STI);
// }

static MCTargetStreamer *createMCAsmTargetStreamer(MCStreamer &S,
                                                   formatted_raw_ostream &OS,
                                                   MCInstPrinter *InstPrint) {
  return new URCLTargetAsmStreamer(S);
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void LLVMInitializeURCLTargetMC() {
  // Register the MC asm info.
  RegisterMCAsmInfo<URCLMCAsmInfo> X(getTheURCLTarget());

  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(getTheURCLTarget(), createURCLMCInstrInfo);

  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(getTheURCLTarget(), createURCLMCRegisterInfo);

  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(getTheURCLTarget(),
                                          createURCLMCSubtargetInfo);

  // Register the MCInstPrinter.
  TargetRegistry::RegisterMCInstPrinter(getTheURCLTarget(),
                                        createURCLMCInstPrinter);

  // Register the MC Code Emitter
  // TargetRegistry::RegisterMCCodeEmitter(getTheURCLTarget(),
                                        // createURCLMCCodeEmitter);

  // Register the obj streamer
  // TargetRegistry::RegisterELFStreamer(getTheURCLTarget(), createMCStreamer);

  // Register the obj target streamer.
  // TargetRegistry::RegisterObjectTargetStreamer(getTheURCLTarget(),
  //                                              createURCLObjectTargetStreamer);

  // Register the asm target streamer.
  // TargetRegistry::RegisterAsmTargetStreamer(getTheURCLTarget(),
  //                                           createMCAsmTargetStreamer);

  // Register the asm backend (as little endian).
  // TargetRegistry::RegisterMCAsmBackend(getTheURCLTarget(), createURCLAsmBackend);
}
