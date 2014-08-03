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
			template<class BaseFunc, class InsideType, class ArgTuple>struct return_type_getter;
			
			template<class Function, class... Insides>struct inside_t
			{
				Function func_;
				tuple<Insides...> inside_;
				typedef tuple<Insides...> this_tuple;
				typedef inside_t<Function, Insides...> this_type;

				static PLASMA_SWITCH_CONSTEXPR index_t size = sizeof...(Insides);
				

				template<class BaseFunc, class... Ts, index_t... Is>PLASMA_CONSTEXPR
					auto run(BaseFunc* ptr, index_sequence<Is...>, tuple<Ts...> const& t)const
					->typename return_type_getter<BaseFunc,this_type,tuple<Ts...>>::type
				{
					return func_((get<Is>(inside_).run(ptr, make_index_count<tuple_element_type<Is, this_tuple>::size>(), t))...);
				}
			};
			template<index_t I>struct arg_place_holder_t
			{
				static PLASMA_SWITCH_CONSTEXPR index_t size = 1;

				template<class BaseFunc,class... Ts,index_t... Is>PLASMA_CONSTEXPR
					tuple_element_type<I,tuple<Ts...>> run(BaseFunc*, index_sequence<Is...>, tuple<Ts...> const& t)const
				{
					return get<I>(t);
				}
			};
			template<class ValueType>struct constant_t
			{
				ValueType value_;
				static PLASMA_SWITCH_CONSTEXPR index_t size = 1;
				ValueType PLASMA_CONSTEXPR run(...)const
				{
					return value_;
				}
			};
			template<class Inside>struct if_t
			{
				Inside inside_;
				static PLASMA_SWITCH_CONSTEXPR index_t size = 1;

				template<class BaseFunc,class... Ts,index_t... Is>PLASMA_CONSTEXPR
					bool run(BaseFunc* ptr, index_sequence<Is...>, tuple<Ts...> const& t)const
				{
					return inside_.run(ptr, plasma::make_index_count<Inside::size>(), t);
				}
			};
			template<class IfInside, class True,class False>struct inside_t<if_t<IfInside>,True,False>
			{
				if_t<IfInside> if_inside_;
				tuple<True,False> inside_;
				static PLASMA_SWITCH_CONSTEXPR index_t size = 2;
				
				template<class BaseFunc, class... Ts, index_t... Is>PLASMA_CONSTEXPR
					auto run(BaseFunc* ptr, index_sequence<Is...>, tuple<Ts...> const& t)const
					->typename return_type_getter<BaseFunc,True,tuple<Ts...>>::type
				{
					return ((if_inside_.run(ptr, make_index_count<1>(), t)) ?
						get<0>(inside_).run(ptr, make_index_count<True::size>(), t) :
						get<1>(inside_).run(ptr, make_index_count<False::size>(), t));
				}
			};
			struct this_t{};
			template<class... Insides>struct inside_t<this_t, Insides... >
			{
				this_t this_object;
				tuple<Insides...> insides_;
				typedef tuple<Insides...> this_tuple;
				static PLASMA_SWITCH_CONSTEXPR index_t size = sizeof...(Insides);

				template<class BaseFunc,class... Ts,index_t... Is>PLASMA_CONSTEXPR
					typename BaseFunc::return_type run(BaseFunc* ptr, index_sequence<Is...>, tuple<Ts...>const& t)const
				{
					return (*ptr)((get<Is>(insides_).run(ptr, make_index_count<tuple_element_type<Is, this_tuple>::size>(), t))...);
				}
			};
			template<class BaseFunc, class Function, class... Insides, class Tuple>
				struct return_type_getter<BaseFunc, inside_t<Function, Insides...>, Tuple>
			{
				typedef decltype(Function{}(typename return_type_getter<BaseFunc, Insides, Tuple >::type{}...)) type;
			};
			template<class BaseFunc,class IfInside,class True,class False,class Tuple>
				struct return_type_getter < BaseFunc, inside_t<if_t<IfInside>, True, False>, Tuple >
			{
				typedef typename return_type_getter<BaseFunc, True, Tuple>::type type;
			};
			template<class BaseFunc,class... Insides,class Tuple>
				struct return_type_getter < BaseFunc, inside_t<this_t, Insides...>, Tuple >
			{
				typedef typename BaseFunc::return_type type;
			};
			template<class BaseFunc,index_t I,class Tuple>
				struct return_type_getter < BaseFunc, arg_place_holder_t<I>, Tuple >
			{
				typedef tuple_element_type<I, Tuple> type;
			};
			template<class BaseFunc,class ValueType,class Tuple>
				struct return_type_getter < BaseFunc, constant_t<ValueType>, Tuple >
			{
				typedef ValueType type;
			};
		}

		template<class Function, class... Insides>PLASMA_CONSTEXPR types::inside_t<Function, Insides...> _(Function f, Insides... is)
		{
			return types::inside_t < Function, Insides... > {f,make_tuple(is...)};
		}
		template<index_t I>PLASMA_CONSTEXPR types::arg_place_holder_t<I> arg()
		{
			return types::arg_place_holder_t<I>{};
		}
		template<class... Insides>PLASMA_CONSTEXPR types::if_t<types::inside_t<Insides...>> if_(Insides... is)
		{
			return types::if_t < types::inside_t<Insides...> > {_(is...)};
		}
		template<class ValueType>PLASMA_CONSTEXPR types::constant_t<ValueType> constant_(ValueType value)
		{
			return types::constant_t< ValueType >{value};
		}
		PLASMA_SWITCH_CONSTEXPR types::this_t this_{};
	}

	template<class Data, class Inside>struct lambda_t;
	template<class RetType, class... ArgTypes, class FirstInside>
		struct lambda_t<RetType(ArgTypes...),FirstInside>
	{
		typedef RetType return_type;
		FirstInside first_;
		static PLASMA_SWITCH_CONSTEXPR index_t size = FirstInside::size;

		PLASMA_CONSTEXPR RetType operator()(ArgTypes... args)const
		{
			return first_.run(this, make_index_count<size>(), make_tuple(args...));
		}
	};

	template<class FuncData, class... Insides>PLASMA_CONSTEXPR lambda_t<FuncData, place_holder::types::inside_t<Insides...>> lambda(Insides... inside)
	{
		return lambda_t < FuncData, place_holder::types::inside_t<Insides...> > {place_holder::_(inside...)};
	}
}