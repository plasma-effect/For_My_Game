// Copyright plasma 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include<plasma/preprocessor.hpp>

namespace plasma
{
	typedef unsigned int index_t;
	template<class>struct sfinae_helper
	{
		typedef void type;
	};
}