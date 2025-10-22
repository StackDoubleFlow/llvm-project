//===-- URCLSelectionDAGInfo.h - URCL SelectionDAG Info -----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the URCL subclass for SelectionDAGTargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_URCL_SELECTION_DAG_INFO_H
#define LLVM_URCL_SELECTION_DAG_INFO_H

#include "llvm/CodeGen/SelectionDAGTargetInfo.h"

#define GET_SDNODE_ENUM
#include "URCLGenSDNodeInfo.inc"

namespace llvm {

/// Holds information about the URCL instruction selection DAG.
class URCLSelectionDAGInfo : public SelectionDAGGenTargetInfo {
public:
  URCLSelectionDAGInfo();

  ~URCLSelectionDAGInfo() override;
};

} // end namespace llvm

#endif // LLVM_URCL_SELECTION_DAG_INFO_H
