//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// UNSUPPORTED: c++98, c++03, c++11, nvrtc

// <chrono>
// class year;

// constexpr year operator+() const noexcept;
// constexpr year operator-() const noexcept;

#include <cuda/std/chrono>
#include <cuda/std/type_traits>
#include <cassert>

#include "test_macros.h"

template <typename Y>
__host__ __device__
constexpr bool testConstexpr()
{
    Y y1{1};
    if (static_cast<int>(+y1) !=  1) return false;
    if (static_cast<int>(-y1) != -1) return false;
    return true;
}

int main(int, char**)
{
    using year  = cuda::std::chrono::year;

    ASSERT_NOEXCEPT(+std::declval<year>());
    ASSERT_NOEXCEPT(-std::declval<year>());

    ASSERT_SAME_TYPE(year, decltype(+std::declval<year>()));
    ASSERT_SAME_TYPE(year, decltype(-std::declval<year>()));

    static_assert(testConstexpr<year>(), "");

    for (int i = 10000; i <= 10020; ++i)
    {
        year year(i);
        assert(static_cast<int>(+year) ==  i);
        assert(static_cast<int>(-year) == -i);
    }

  return 0;
}
