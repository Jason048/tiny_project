tiny.func @main() {
  %0 = tiny.constant dense<[[1.000000e+00, 2.000000e+00, 3.000000e+00], [4.000000e+00, 5.000000e+00, 6.000000e+00]]> : tensor<2x3xf64>
  %2 = tiny.transpose(%0 : tensor<2x3xf64>) to tensor<3x2xf64>
  %3 = tiny.mul %2, %2 : tensor<3x2xf64>
  tiny.print %3 : tensor<3x2xf64>
  tiny.return
}

