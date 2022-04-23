//===- ShapeInferenceInterface.h - Interface definitions for ShapeInference -=//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the shape inference interfaces defined
// in ShapeInferenceInterface.td.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_TUTORIAL_TINY_SHAPEINFERENCEINTERFACE_H_
#define MLIR_TUTORIAL_TINY_SHAPEINFERENCEINTERFACE_H_

#include "mlir/IR/OpDefinition.h"

namespace mlir {
namespace tiny {

/// Include the auto-generated declarations.
#include "tiny/ShapeInferenceOpInterfaces.h.inc"

} // namespace tiny
} // namespace mlir

#endif // MLIR_TUTORIAL_TINY_SHAPEINFERENCEINTERFACE_H_
