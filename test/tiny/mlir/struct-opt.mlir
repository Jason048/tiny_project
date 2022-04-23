tiny.func @main() {
  %0 = tiny.struct_constant [
    [dense<4.000000e+00> : tensor<2x2xf64>], dense<4.000000e+00> : tensor<2x2xf64>
  ] : !tiny.struct<!tiny.struct<tensor<*xf64>>, tensor<*xf64>>
  %1 = tiny.struct_access %0[0] : !tiny.struct<!tiny.struct<tensor<*xf64>>, tensor<*xf64>> -> !tiny.struct<tensor<*xf64>>
  %2 = tiny.struct_access %1[0] : !tiny.struct<tensor<*xf64>> -> tensor<*xf64>
  tiny.print %2 : tensor<*xf64>
  tiny.return
}

// CHECK-LABEL: tiny.func @main
// CHECK-NEXT: %[[CST:.*]] = tiny.constant dense<4.0
// CHECK-NEXT: tiny.print %[[CST]]
