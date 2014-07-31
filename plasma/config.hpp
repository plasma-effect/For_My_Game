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

#ifndef PLASMA_NAMESPACE
#define PLASMA_NAMESPACE std
#endif

#ifndef PLASMA_TUPLE_INCLUDE
#define PLASMA_TUPLE_INCLUDE <tuple>
#endif

#ifndef PLASMA_ARRAY_INCLUDE
#define PLASMA_ARRAY_INCLUDE <array>
#endif