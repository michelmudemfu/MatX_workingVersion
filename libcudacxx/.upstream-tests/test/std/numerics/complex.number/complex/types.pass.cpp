//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//

// <cuda/std/complex>

// template<class T>
// class complex
// {
// public:
//   typedef T value_type;
//   ...
// };

#include <cuda/std/complex>
#include <cuda/std/type_traits>

#include "test_macros.h"

template <class T>
__host__ __device__ void
test()
{
    typedef cuda::std::complex<T> C;
    static_assert((cuda::std::is_same<typename C::value_type, T>::value), "");
}

int main(int, char**)
{
    test<float>();
    test<double>();
// CUDA treats long double as double
//  test<long double>();

  return 0;
}
