//===- TinyCombine.cpp - Tiny High Level Optimizer --------------------------===//
//===----------------------------------------------------------------------===//
//
// This file implements a set of simple combiners for optimizing operations in
// the Tiny dialect.
//
//===----------------------------------------------------------------------===//

#include "mlir/IR/Matchers.h"
#include "mlir/IR/PatternMatch.h"
#include "tiny/Dialect.h"
#include <numeric>
using namespace mlir;
using namespace tiny;

namespace {
/// Include the patterns defined in the Declarative Rewrite framework.
#include "TinyCombine.inc"
} // namespace

/// Fold constants.
OpFoldResult ConstantOp::fold(ArrayRef<Attribute> operands) {
  return getValue();
}

/// Fold struct constants.
OpFoldResult StructConstantOp::fold(ArrayRef<Attribute> operands) {
  return getValue();
}

/// Fold simple struct access operations that access into a constant.
OpFoldResult StructAccessOp::fold(ArrayRef<Attribute> operands) {
  auto structAttr = operands.front().dyn_cast_or_null<mlir::ArrayAttr>();
  if (!structAttr)
    return nullptr;

  size_t elementIndex = getIndex();
  return structAttr[elementIndex];
}

/// This is an example of a c++ rewrite pattern for the TransposeOp. It
/// optimizes the following scenario: transpose(transpose(x)) -> x
struct SimplifyRedundantTranspose : public mlir::OpRewritePattern<TransposeOp> {
 
  SimplifyRedundantTranspose(mlir::MLIRContext *context)
      : OpRewritePattern<TransposeOp>(context, /*benefit=*/1) {}

  /// TODO Redundant code elimination
  mlir::LogicalResult
  matchAndRewrite(TransposeOp op,
                  mlir::PatternRewriter &rewriter) const override {


    // Step 1: Get the input of the current transpose.
    // Hint: For op, there is a function: op.getOperand(), it returns the parameter of a TransposeOp and its type is mlir::Value.

    /* 
     *
     *  Write your code here.
     *
     */


    // Step 2: Check whether the input is defined by another transpose. If not defined, return failure().
    // Hint: For mlir::Value type, there is a function you may use: 
    //       template<typename OpTy> OpTy getDefiningOp () const
 	  //       If this value is the result of an operation of type OpTy, return the operation that defines it

    /* 
     *
     *  Write your code here.
     *  if () return failure();
     *
     */

    // step 3: Otherwise, we have a redundant transpose. Use the rewriter to remove redundancy.
    // Hint: For mlir::PatternRewriter, there is a function you may use to remove redundancy: 
    //       void replaceOp (mlir::Operation *op, mlir::ValueRange newValues)
    //       Operations of the second argument will be replaced by the first argument.

    /* 
     *
     *  Write your code here.
     *
     */
    
    return success();
  }
};

/// Register our patterns as "canonicalization" patterns on the TransposeOp so
/// that they can be picked up by the Canonicalization framework.
void TransposeOp::getCanonicalizationPatterns(RewritePatternSet &results,
                                              MLIRContext *context) {
  results.add<SimplifyRedundantTranspose>(context);
}

/// Register our patterns as "canonicalization" patterns on the ReshapeOp so
/// that they can be picked up by the Canonicalization framework.
void ReshapeOp::getCanonicalizationPatterns(RewritePatternSet &results,
                                            MLIRContext *context) {
  results.add<ReshapeReshapeOptPattern, RedundantReshapeOptPattern,
              FoldConstantReshapeOptPattern>(context);
}
