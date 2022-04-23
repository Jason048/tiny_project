/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

class ShapeInference;
namespace detail {
struct ShapeInferenceInterfaceTraits {
  struct Concept {
    void (*inferShapes)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ShapeInference;
    Model() : Concept{inferShapes} {}

    static inline void inferShapes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ShapeInference;
    FallbackModel() : Concept{inferShapes} {}

    static inline void inferShapes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
  };
};template <typename ConcreteOp>
struct ShapeInferenceTrait;

} // namespace detail
class ShapeInference : public ::mlir::OpInterface<ShapeInference, detail::ShapeInferenceInterfaceTraits> {
public:
  using ::mlir::OpInterface<ShapeInference, detail::ShapeInferenceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::ShapeInferenceTrait<ConcreteOp> {};
  void inferShapes();
};
namespace detail {
  template <typename ConcreteOp>
  struct ShapeInferenceTrait : public ::mlir::OpInterface<ShapeInference, detail::ShapeInferenceInterfaceTraits>::Trait<ConcreteOp> {
  };
}// namespace detail
template<typename ConcreteOp>
void detail::ShapeInferenceInterfaceTraits::Model<ConcreteOp>::inferShapes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).inferShapes();
}
template<typename ConcreteOp>
void detail::ShapeInferenceInterfaceTraits::FallbackModel<ConcreteOp>::inferShapes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->inferShapes(tablegen_opaque_val);
}
