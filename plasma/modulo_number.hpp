// Copyright plasma 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/config.hpp>

namespace plasma
{
    template<class T,T Max>class modulo_number
    {
	static_assert(Max > T(),"template parameter Max must be over T()");
	T value_;
    public:
	static PLASMA_SWITCH_CONSTEXPR T max = Max;
	typedef modulo_number<T,Max> type;
	typedef T value_type;

	PLASMA_CONSTEXPR modulo_number(T const& v):
	    value_(v < T() ?  ((v % Max) + Max) : (v % Max)){}
	PLASMA_CONSTEXPR modulo_number(type const& v):
	    value_(v.value_ < T() ? ((v.value_ & Max) + Max): (v % Max)){}

	PLASMA_CONSTEXPR operator T()const
	{
	    return value_;
	}
    };
}
