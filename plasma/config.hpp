// Copyright plasma-effect 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if defined(_MSC_VER)
#	if _MSC_VER <= 1800
#	define PLASMA_CONSTEXPR
#	define PLASMA_SWITCH_CONSTEXPR const
#	else
#	define PLASMA_CONSTEXPR constexpr
#	define PLASMA_SWITCH_CONSTEXPR constexpr
#	endif
#else
#define PLASMA_CONSTEXPR constexpr
#define PLASMA_SWITCH_CONSTEXPR constexpr
#endif

#if defined(USE_SPROUT_TUPLE)
#define PLASMA_TUPLE_NAMESPACE sprout
#else
#define PLASMA_TUPLE_NAMESPACE std
#endif