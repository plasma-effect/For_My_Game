// Copyright plasma-effect 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include<plasma/utility.hpp>
#include<plasma/config.hpp>
#include<plasma/index_sequence.hpp>
#include PLASMA_ARRAY_INCLUDE

namespace plasma
{
	namespace algorithm
	{
		namespace detail
		{
			template<class F, index_t... Is>PLASMA_CONSTEXPR auto make_array_impl(F func,index_sequence<Is...>)
				->PLASMA_NAMESPACE::array<decltype(func(0u)), sizeof...(Is) >
			{
				return {func(Is)...};
			}
		}

		template<index_t B, index_t E, class F>PLASMA_CONSTEXPR auto make_array(F func)
			->PLASMA_NAMESPACE::array<decltype(func(0u)), E-B+1 >
		{
			return detail::make_array_impl(func, make_index_range<B, E>());
		}

		template<class InputIterator, class Predicate>
			inline void ptr_delete_if(InputIterator beg, InputIterator end, Predicate pred)
		{
			for (; beg != end; ++beg)
			{
				if (*beg && pred(**beg))
				{
					(*beg).reset();
				}
			}
		}
	}
}