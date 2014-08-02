//#pragma message(__TIME__)
//#pragma message(__DATE__)

#include<plasma/lambda.hpp>
#include<plasma/functions.hpp>
//#include<iostream>

int main()
{
    using namespace plasma::place_holder;
    using namespace plasma::functions;
    using namespace plasma::operators;
    PLASMA_CONSTEXPR auto func = plasma::lambda<int(int)>
	(if_(is_zero, arg<0>()),
	constant_(1),
	_(mul, arg<0>(), _(this_, _(prev, arg<0>()))));
    PLASMA_CONSTEXPR auto N = func(3);
    //PLASMA_CONSTEXPR auto M = func(0);
    //std::cout<< N<<","<<M <<std::endl;
}
