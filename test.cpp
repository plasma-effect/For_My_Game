#pragma message(__TIME__)
#pragma message(__DATE__)

#include<utility>
#include<plasma/static_assert.hpp>

template<std::size_t N>struct fact
{
	static const int value = N * fact<N - 1>::value;
};
template<>struct fact < 0 >
{
	static const int value = 1;
};

int main()
{
	PLASMA_PP_STATIC_ASSERT_1NUM(false, "fact<5>::value == ", fact<5>::value, );
}
