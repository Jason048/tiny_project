tiny.func private @multiply_transpose(%arg0: tensor<*xf64>, %arg1: tensor<*xf64>) -> tensor<*xf64> {
  %0 = tiny.transpose(%arg0 : tensor<*xf64>) to tensor<*xf64>
  %1 = tiny.transpose(%arg1 : tensor<*xf64>) to tensor<*xf64>
  %2 = tiny.mul %0, %1 : tensor<*xf64>
  tiny.return %2 : tensor<*xf64>
}
tiny.func @main() {
  %0 = tiny.constant dense<[[1.000000e+00, 2.000000e+00, 3.000000e+00], [4.000000e+00, 5.000000e+00, 6.000000e+00]]> : tensor<2x3xf64>
  %1 = tiny.reshape(%0 : tensor<2x3xf64>) to tensor<2x3xf64>
  %2 = tiny.constant dense<[1.000000e+00, 2.000000e+00, 3.000000e+00, 4.000000e+00, 5.000000e+00, 6.000000e+00]> : tensor<6xf64>
  %3 = tiny.reshape(%2 : tensor<6xf64>) to tensor<2x3xf64>
  %4 = tiny.generic_call @multiply_transpose(%1, %3) : (tensor<2x3xf64>, tensor<2x3xf64>) -> tensor<*xf64>
  %5 = tiny.generic_call @multiply_transpose(%3, %1) : (tensor<2x3xf64>, tensor<2x3xf64>) -> tensor<*xf64>
  tiny.print %5 : tensor<*xf64>
  tiny.return
}

// CHECK-NOT: func @multiply_transpose
// CHECK-NOT: tensor<*xf64>

// CHECK-LABEL: func @main()
// CHECK:         [[VAL_0:%.*]] = tiny.constant dense<{{\[\[}}1.000000e+00, 2.000000e+00, 3.000000e+00], [4.000000e+00, 5.000000e+00, 6.000000e+00]]> : tensor<2x3xf64>
// CHECK:         [[VAL_1:%.*]] = tiny.transpose([[VAL_0]] : tensor<2x3xf64>) to tensor<3x2xf64>
// CHECK:         [[VAL_2:%.*]] = tiny.mul [[VAL_1]], [[VAL_1]] : tensor<3x2xf64>
// CHECK:         tiny.print [[VAL_2]] : tensor<3x2xf64>
// CHECK:         tiny.return
