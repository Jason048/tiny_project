//===- Dialect.h - Dialect definition for the Tiny IR ----------------------===//
//===----------------------------------------------------------------------===//
//
// This file implements the IR Dialect for the Tiny language.
// See docs/Tutorials/Tiny/Ch-2.md for more information.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_TUTORIAL_TINY_DIALECT_H_
#define MLIR_TUTORIAL_TINY_DIALECT_H_

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/FunctionInterfaces.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/CallInterfaces.h"
#include "mlir/Interfaces/CastInterfaces.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"
#include "tiny/ShapeInferenceInterface.h"

namespace mlir {
namespace tiny {
namespace detail {
struct StructTypeStorage;
} // namespace detail
} // namespace tiny
} // namespace mlir

/// Include the auto-generated header file containing the declaration of the tiny
/// dialect.
#include "tiny/Dialect.h.inc"

//===----------------------------------------------------------------------===//
// Tiny Operations
//===----------------------------------------------------------------------===//

/// Include the auto-generated header file containing the declarations of the
/// tiny operations.
#define GET_OP_CLASSES
#include "tiny/Ops.h.inc"

namespace mlir {
namespace tiny {

//===----------------------------------------------------------------------===//
// Tiny Types
//===----------------------------------------------------------------------===//

/// This class defines the Tiny struct type. It represents a collection of
/// element types. All derived types in MLIR must inherit from the CRTP class
/// 'Type::TypeBase'. It takes as template parameters the concrete type
/// (StructType), the base class to use (Type), and the storage class
/// (StructTypeStorage).
class StructType : public mlir::Type::TypeBase<StructType, mlir::Type,
                                               detail::StructTypeStorage> {
public:
  /// Inherit some necessary constructors from 'TypeBase'.
  using Base::Base;

  /// Create an instance of a `StructType` with the given element types. There
  /// *must* be atleast one element type.
  static StructType get(llvm::ArrayRef<mlir::Type> elementTypes);

  /// Returns the element types of this struct type.
  llvm::ArrayRef<mlir::Type> getElementTypes();

  /// Returns the number of element type held by this struct.
  size_t getNumElementTypes() { return getElementTypes().size(); }
};
} // namespace tiny
} // namespace mlir

#endif // MLIR_TUTORIAL_TINY_DIALECT_H_
