// Copyright plasma-effect 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#define PLASMA_PP_CAT(a, b) PLASMA_PP_CAT_I(a,b)
#define PLASMA_PP_CAT_I(a,b) a ## b

#define PLASMA_PP_STRINGIZE(a) PLASMA_PP_STRINGIZE_I(a)
#define PLASMA_PP_STRINGIZE_I(a) #a

#define PLASMA_PP_VARIADIC_SIZE_I_CAT(a,b) PLASMA_PP_VARIADIC_SIZE_I_CAT_I(a,b)
#define PLASMA_PP_VARIADIC_SIZE_I_CAT_I(a,b) a ## b
#define PLASMA_PP_VARIADIC_SIZE(...) PLASMA_PP_VARIADIC_SIZE_I((__VA_ARGS__,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1))
#define PLASMA_PP_VARIADIC_SIZE_I(arg) PLASMA_PP_VARIADIC_SIZE_I_CAT_I(PLASMA_PP_VARIADIC_SIZE_I2,arg)
#define PLASMA_PP_VARIADIC_SIZE_I2(t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47,t48,t49,t50,t51,t52,t53,t54,t55,t56,t57,t58,t59,t60,t61,t62,n,...) n