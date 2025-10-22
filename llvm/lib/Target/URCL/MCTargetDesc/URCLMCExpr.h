//===-- URCLMCExpr.h - URCL specific MC expression classes --------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_URCL_MCEXPR_H
#define LLVM_URCL_MCEXPR_H

#include "llvm/MC/MCExpr.h"


namespace llvm {

/// A expression in URCL machine code.
class URCLMCExpr : public MCSpecifierExpr {
public:
  friend class URCLMCAsmInfo;
  using Specifier = Spec;
  /// Specifies the type of an expression.

public:
  /// Creates an URCL machine code expression.
  static const URCLMCExpr *create(Specifier S, const MCExpr *Expr,
                                 bool isNegated, MCContext &Ctx);

  /// Gets the name of the expression.
  const char *getName() const;
  /// Evaluates the fixup as a constant value.
  bool evaluateAsConstant(int64_t &Result) const;

public:
  static Specifier parseSpecifier(StringRef Name);

private:
  int64_t evaluateAsInt64(int64_t Value) const;

private:
  explicit URCLMCExpr(Specifier S, const MCExpr *Expr)
      : MCSpecifierExpr(Expr, S) {}
};

} // end namespace llvm

#endif // LLVM_URCL_MCEXPR_H
