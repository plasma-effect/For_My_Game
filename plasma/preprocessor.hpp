// Copyright plasma-effect 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#define PLASMA_PP_CAT(a, b) PLASMA_PP_CAT_I(a,b)
#define PLASMA_PP_CAT_I(a,b) a ## b

#define PLASMA_PP_STRINGIZE(a) PLASMA_PP_STRINGIZE_I(a)
#define PLASMA_PP_STRINGIZE_I(a) #a

#ifdef _MSC_VER
#define PLASMA_PP_TUPLE_FUNCTION_I(a,b) a ## b
#define PLASMA_PP_TUPLE_FUNCTION(macro,tuple) PLASMA_PP_TUPLE_FUNCTION_I(macro,tuple)
#define PLASMA_PP_TUPLE_FUNCTION2_I(a,b) a ## b
#define PLASMA_PP_TUPLE_FUNCTION2(macro,tuple) PLASMA_PP_TUPLE_FUNCTION2_I(macro,tuple)
#else
#define PLASMA_PP_TUPLE_FUNCTION(macro,tuple) macro tuple
#define PLASMA_PP_TUPLE_FUNCTION2(macro,tuple) macro tuple
#endif

#define PLASMA_PP_VARIADIC_SIZE(...) PLASMA_PP_TUPLE_FUNCTION(PLASMA_PP_VARIADIC_SIZE_I,(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1))
#define PLASMA_PP_VARIADIC_SIZE_I(t16,t15,t14,t13,t12,t11,t10,t9,t8,t7,t6,t5,t4,t3,t2,t1,n,...) n

#define PLASMA_PP_PREFIX_VALUE_DEFINE(...) PLASMA_PP_TUPLE_FUNCTION2(PLASMA_PP_PREFIX_VALUE_DEFINE_I_1(PLASMA_PP_VARIADIC_SIZE(__VA_ARGS__)),(__VA_ARGS__))
#define PLASMA_PP_PREFIX_VALUE_DEFINE_I(a,b) PLASMA_PP_PREFIX_VALUE_DEFINE_I_2(a,b)
#define PLASMA_PP_PREFIX_VALUE_DEFINE_I_1(a) PLASMA_PP_CAT(PLASMA_PP_PREFIX_VALUE_DEFINE_I_,a)
#define PLASMA_PP_PREFIX_VALUE_DEFINE_I_2(a,b) a ## b
#define PLASMA_PP_PREFIX_VALUE_DEFINE_I_3(prefix,type,name) type PLASMA_PP_PREFIX_VALUE_DEFINE_I(prefix,name)
#define PLASMA_PP_PREFIX_VALUE_DEFINE_I_4(prefix,type,name,init) type PLASMA_PP_PREFIX_VALUE_DEFINE_I(prefix,name) init