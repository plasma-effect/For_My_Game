// Copyright plasma 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/index_sequence.hpp>
#include<plasma/config.hpp>


namespace plasma
{
	namespace detail
	{
		template<class Func, class Tuple, class Index>struct tuple_to_func_impl;
		template<class Func, class Tuple, index_t... Is>struct tuple_to_func_impl<Func,Tuple,index_sequence<Is...>>
		{
			static PLASMA_CONSTEXPR auto run(Func&& func, Tuple&& tup)->decltype(func(PLASMA_TUPLE_NAMESPACE ::get<Is>(tup)...))
			{
				return func(PLASMA_TUPLE_NAMESPACE ::get<Is>(tup)...);
			}
		};
		template<class Func, class Tuple, class Index>struct tuple_to_func_impl2;
		template<class Func, class Tuple, index_t... Is>struct tuple_to_func_impl2<Func, Tuple, index_sequence<Is...>>
		{
			static PLASMA_CONSTEXPR auto run(Func& func, Tuple& tup)->decltype(func(PLASMA_TUPLE_NAMESPACE ::get<Is>(tup)...))
			{
				return func(PLASMA_TUPLE_NAMESPACE ::get<Is>(tup)...);
			}
		};
		template<class Func, class Tuple, class Index>struct tuple_to_func_impl3;
		template<class Func, class Tuple, index_t... Is>struct tuple_to_func_impl3<Func, Tuple, index_sequence<Is...>>
		{
			static PLASMA_CONSTEXPR auto run(Func&& func, Tuple& tup)->decltype(func(PLASMA_TUPLE_NAMESPACE ::get<Is>(tup)...))
			{
				return func(PLASMA_TUPLE_NAMESPACE ::get<Is>(tup)...);
			}
		};
		template<class Func, class Tuple, class Index>struct tuple_to_func_impl4;
		template<class Func, class Tuple, index_t... Is>struct tuple_to_func_impl4<Func, Tuple, index_sequence<Is...>>
		{
			static PLASMA_CONSTEXPR auto run(Func& func, Tuple&& tup)->decltype(func(PLASMA_TUPLE_NAMESPACE ::get<Is>(tup)...))
			{
				return func(PLASMA_TUPLE_NAMESPACE ::get<Is>(tup)...);
			}
		};
	}
	template<class Func, class Tuple>PLASMA_CONSTEXPR auto tuple_to_func(Func&& func, Tuple&& tup)
		->decltype(detail::tuple_to_func_impl<Func, Tuple, index_count<PLASMA_TUPLE_NAMESPACE ::tuple_size<Tuple>::value>::type>::run(func, tup))
	{
		return detail::tuple_to_func_impl<Func, Tuple, index_count<PLASMA_TUPLE_NAMESPACE ::tuple_size<Tuple>::value>::type>::run(func, tup);
	}
	template<class Func, class Tuple>PLASMA_CONSTEXPR auto tuple_to_func(Func& func, Tuple& tup)
		->decltype(detail::tuple_to_func_impl2<Func, Tuple, index_count<PLASMA_TUPLE_NAMESPACE ::tuple_size<Tuple>::value>::type>::run(func, tup))
	{
		return detail::tuple_to_func_impl2<Func, Tuple, index_count<PLASMA_TUPLE_NAMESPACE ::tuple_size<Tuple>::value>::type>::run(func, tup);
	}
	template<class Func, class Tuple>PLASMA_CONSTEXPR auto tuple_to_func(Func&& func, Tuple& tup)
		->decltype(detail::tuple_to_func_impl3<Func, Tuple, index_count<PLASMA_TUPLE_NAMESPACE ::tuple_size<Tuple>::value>::type>::run(func, tup))
	{
		return detail::tuple_to_func_impl3<Func, Tuple, index_count<PLASMA_TUPLE_NAMESPACE ::tuple_size<Tuple>::value>::type>::run(func, tup);
	}
	template<class Func, class Tuple>PLASMA_CONSTEXPR auto tuple_to_func(Func& func, Tuple&& tup)
		->decltype(detail::tuple_to_func_impl4<Func, Tuple, index_count<PLASMA_TUPLE_NAMESPACE ::tuple_size<Tuple>::value>::type>::run(func, tup))
	{
		return detail::tuple_to_func_impl4<Func, Tuple, index_count<PLASMA_TUPLE_NAMESPACE ::tuple_size<Tuple>::value>::type>::run(func, tup);
	}
}