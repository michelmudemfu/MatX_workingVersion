//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11
// UNSUPPORTED: nvrtc

// <utility>

// template<class T, T... I>
// struct integer_sequence
// {
//     typedef T type;
//
//     static constexpr size_t size() noexcept;
// };

// This test is a conforming extension.  The extension turns undefined behavior
//  into a compile-time error.

#include <cuda/std/utility>

#include "test_macros.h"

int main(int, char**) {
    // Should fail to compile, since float is not an integral type
    using floatmix = cuda::std::integer_sequence<float>;
    floatmix::value_type I;
    return 0;
}
