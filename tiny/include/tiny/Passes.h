//===- Passes.h - Tiny Passes Definition -----------------------------------===//
//===----------------------------------------------------------------------===//
//
// This file exposes the entry points to create compiler passes for Tiny.
//
//===----------------------------------------------------------------------===//

#ifndef TINY_PASSES_H
#define TINY_PASSES_H

#include <memory>

namespace mlir {
class Pass;

namespace tiny {
std::unique_ptr<Pass> createShapeInferencePass();

/// Create a pass for lowering to operations in the `Affine` and `Std` dialects,
/// for a subset of the Tiny IR (e.g. matmul).
std::unique_ptr<mlir::Pass> createLowerToAffinePass();

/// Create a pass for lowering operations the remaining `Tiny` operations, as
/// well as `Affine` and `Std`, to the LLVM dialect for codegen.
std::unique_ptr<mlir::Pass> createLowerToLLVMPass();

} // namespace tiny
} // namespace mlir

#endif // TINY_PASSES_H
