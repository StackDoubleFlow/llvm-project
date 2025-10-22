add_llvm_component_library(LLVMURCLDesc
  URCLInstPrinter.cpp
  URCLMCAsmInfo.cpp
  URCLMCExpr.cpp
  URCLMCTargetDesc.cpp
  URCLTargetStreamer.cpp

  LINK_COMPONENTS
  MC
  URCLInfo
  Support
  TargetParser

  ADD_TO_COMPONENT
  URCL
)

add_dependencies(LLVMURCLDesc URCLCommonTableGen)

