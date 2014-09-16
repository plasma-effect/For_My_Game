// Copyright plasma-effect 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include<plasma/utility.hpp>

namespace plasma
{
	template<class T,class F>struct func_obj_t
	{
		F func_;
		operator T()const
		{
			return func_();
		}
	};

	template<class T, class F>func_obj_t<T, F> func_obj(F func)
	{
		return func_obj_t< T, F >{func};
	}
}