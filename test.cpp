#pragma message(__TIME__)
#pragma message(__DATE__)

#include<plasma/static_assert.hpp>
#include<iostream>

constexpr int fact(int N)
{
    return (N == 0 ? 1 : N * fact(N - 1));
}

int main()
{
    PLASMA_PP_STATIC_ASSERT_1NUM(false,"fact(5) == ",fact(5),);
}
