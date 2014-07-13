// Copyright plasma 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/config.hpp>

namespace plasma
{
    template<class T,T Min,T Max>class range_number
    {
	static_assert(Min<=Max,"template parameter Min must be less than Max");
	T value_;
    public:
	static PLASMA_SWITCH_CONSTEXPR T min = Min;
	static PLASMA_SWITCH_CONSTEXPR T max = Max;
	typedef T value_type;
	typedef range_number<T,Min,Max> type;

	PLASMA_CONSTEXPR range_number(T v = T()):
	    value_((v < Min ? Min :(v > Max ? Max : v))){}
	PLASMA_CONSTEXPR range_number(type const& v):
	    value_(v.value_){}

	PLASMA_CONSTEXPR operator T()const{return value_;}
    };
}
