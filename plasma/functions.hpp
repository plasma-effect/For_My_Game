// Copyright plasma 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/config.hpp>
#include<plasma/utility.hpp>

namespace plasma
{
	namespace operators
	{

#		define PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(op,name)\
		struct PLASMA_PP_CAT(name,_t)\
		{\
			template<class T,class U>PLASMA_CONSTEXPR auto operator()(T a, U b)const->decltype((a op b))\
			{\
				return a op b;\
			}\
		};\
		PLASMA_SWITCH_CONSTEXPR PLASMA_PP_CAT(name,_t) name{}


		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(+, add);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(-, sub);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(*, mul);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(/, div);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(%, mod);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(<< , l_shift);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(>> , r_shift);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(&&, logic_and);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(|| , logic_or);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(< , less_than);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(> , more_than);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(<= ,less_equal);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(>= , more_equal);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(== , equal);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(!= , not_equal);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(&, bit_and);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(| , bit_or);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_2ARGS(^, bit_xor);


#		define PLASMA_PP_MAKE_OPERATOR_OBJECT_1ARGS(op,name)\
		struct PLASMA_PP_CAT(name,_t)\
		{\
			template<class T>PLASMA_CONSTEXPR auto operator()(T a)const->decltype((op a))\
			{\
				return op a;\
			}\
		};\
		PLASMA_SWITCH_CONSTEXPR PLASMA_PP_CAT(name,_t) name{}

		PLASMA_PP_MAKE_OPERATOR_OBJECT_1ARGS(!, logic_not);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_1ARGS(+, plus);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_1ARGS(-, minus);
		PLASMA_PP_MAKE_OPERATOR_OBJECT_1ARGS(~, bit_not);

	}

	namespace functions
	{

#		define PLASMA_PP_MAKE_FUNCTION_OBJECT_1ARGS(impl,name)\
		struct PLASMA_PP_CAT(name,_t)\
		{\
			template<class T>auto operator()(T a)const->decltype(impl)\
			{\
				return impl;\
			}\
		};\
		PLASMA_SWITCH_CONSTEXPR PLASMA_PP_CAT(name,_t) name{}

		PLASMA_PP_MAKE_FUNCTION_OBJECT_1ARGS((a + 1), succ);
		PLASMA_PP_MAKE_FUNCTION_OBJECT_1ARGS((a - 1), prev);
		PLASMA_PP_MAKE_FUNCTION_OBJECT_1ARGS((a == 0), is_zero);




	}
}