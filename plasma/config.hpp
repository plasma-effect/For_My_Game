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
