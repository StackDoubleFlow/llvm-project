add_llvm_component_group(URCL)

set(LLVM_TARGET_DEFINITIONS URCL.td)

tablegen(LLVM URCLGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM URCLGenCallingConv.inc -gen-callingconv)
tablegen(LLVM URCLGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM URCLGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM URCLGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM URCLGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM URCLGenSDNodeInfo.inc -gen-sd-node-info)
tablegen(LLVM URCLGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(URCLCommonTableGen)

add_llvm_target(URCLCodeGen
  URCLAsmPrinter.cpp
  URCLFrameLowering.cpp
  URCLInstrInfo.cpp
  URCLISelDAGToDAG.cpp
  URCLISelLowering.cpp
  URCLMCInstLower.cpp
  URCLRegisterInfo.cpp
  URCLSelectionDAGInfo.cpp
  URCLSubtarget.cpp
  URCLTargetMachine.cpp
  URCLTargetTransformInfo.cpp

  DEPENDS
  intrinsics_gen

  LINK_COMPONENTS
  Analysis
  URCLDesc
  URCLInfo
  AsmPrinter
  CodeGen
  CodeGenTypes
  Core
  MC
  SelectionDAG
  Support
  Target
  TargetParser
  TransformUtils

  ADD_TO_COMPONENT
  URCL
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
