//===- MLIRGen.h - MLIR Generation from a Tiny AST -------------------------===//
//===----------------------------------------------------------------------===//
//
// This file declares a simple interface to perform IR generation targeting MLIR
// from a Module AST for the Tiny language.
//
//===----------------------------------------------------------------------===//

#ifndef TINY_MLIRGEN_H
#define TINY_MLIRGEN_H

#include <memory>

namespace mlir {
class MLIRContext;
template <typename OpTy>
class OwningOpRef;
class ModuleOp;
} // namespace mlir

namespace tiny {
class ModuleAST;

/// Emit IR for the given Tiny moduleAST, returns a newly created MLIR module
/// or nullptr on failure.
mlir::OwningOpRef<mlir::ModuleOp> mlirGen(mlir::MLIRContext &context,
                                          ModuleAST &moduleAST);
} // namespace tiny

#endif // TINY_MLIRGEN_H
