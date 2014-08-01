// Copyright plasma 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)

#pragma once
//#define DEBAG
#include<plasma/tuple.hpp>
#include<plasma/index_sequence.hpp>

namespace plasma
{
	namespace place_holder
	{
		namespace types
		{
			template<class Function, class... Insides>struct inside_t
			{
				Function func_;
				tuple<Insides...> inside_;
				typedef tuple<Insides...> this_tuple;

				static PLASMA_SWITCH_CONSTEXPR index_t size = sizeof...(Insides);
				

				template<class BaseFunc, class... Ts, index_t... Is>PLASMA_CONSTEXPR
					auto run(BaseFunc const& ptr, index_sequence<Is...>, tuple<Ts...> const& t)
					->decltype(func_((get<Is>(inside_).run(ptr, make_index_count<tuple_element_type<Is, this_tuple>::size>(), t))...))
				{
					return func_((get<Is>(inside_).run(ptr, make_index_count<tuple_element_type<Is, this_tuple>::size>(), t))...);
				}
			};
			template<index_t I>struct arg_place_holder_t
			{
				static PLASMA_SWITCH_CONSTEXPR index_t size = 1;

				template<class BaseFunc,class... Ts,index_t... Is>PLASMA_CONSTEXPR
					tuple_element_type<I,tuple<Ts...>> run(BaseFunc const& ptr, index_sequence<Is...>, tuple<Ts...> const& t)
				{
					return get<I>(t);
				}
			};
		}
		template<class Function, class... Insides>PLASMA_CONSTEXPR types::inside_t<Function, Insides...> _(Function f, Insides... is)
		{
			return types::inside_t < Function, Insides... > {f, { is... }};
		}
		template<index_t I>PLASMA_CONSTEXPR types::arg_place_holder_t<I> arg()
		{
			return types::arg_place_holder_t<I>{};
		}
	}

	template<class Data, class Inside>struct lambda_t;
	template<class RetType, class... ArgTypes, class FirstInside>
		struct lambda_t<RetType(ArgTypes...),FirstInside>
	{
		FirstInside first_;

		PLASMA_CONSTEXPR RetType operator()(ArgTypes... args)
		{
			return first_.run(this, make_index_count<FirstInside::size>(), make_tuple(args...));
		}
	};

	template<class FuncData, class... Insides>PLASMA_CONSTEXPR lambda_t<FuncData, place_holder::types::inside_t<Insides...>> lambda(Insides... inside)
	{
		return lambda_t < FuncData, place_holder::types::inside_t<Insides...> > {place_holder::_(inside...)};
	}
}