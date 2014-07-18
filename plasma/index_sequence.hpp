// Copyright plasma 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/config.hpp>
#include<plasma/utility.hpp>

namespace plasma
{
	template<index_t... Indexes>struct index_sequence{};
	namespace detail
	{
		template<index_t N>struct is_even
		{
			static PLASMA_SWITCH_CONSTEXPR bool value = (N % 2 == 0);
		};

		template<bool IsEven, index_t N,class Index>struct index_count_next;

		template<index_t N, index_t... Indexes>struct index_count_next<true, N, index_sequence<Indexes...>>
		{
			typedef index_sequence<Indexes..., (N + Indexes)...> type;
		};
		template<index_t N, index_t... Indexes>struct index_count_next<false, N, index_sequence<Indexes...>>
		{
			typedef index_sequence<Indexes..., (N + Indexes)..., 2 * N> type;
		};
		template<class Index, index_t N>struct index_range_impl;
		template<index_t N, index_t... Indexes>struct index_range_impl<index_sequence<Indexes...>, N>
		{
			typedef index_sequence<(N + Indexes)...> type;
		};

	}
	template<index_t N>struct index_count
	{
		typedef typename 
			detail::index_count_next<detail::is_even<N>::value, N/2,typename index_count<N / 2>::type>::type type;
	};
	template<>struct index_count<0u>
	{
		typedef index_sequence<> type;
	};
	template<index_t Begin, index_t End>struct index_range
	{
		typedef detail::index_range_impl<typename index_count<End - Begin + 1>::type, Begin> type;
	};

	template<index_t N>PLASMA_CONSTEXPR typename index_count<N>::type make_index_count()
	{
		return typename index_count<N>::type{};
	}
	template<index_t Begin, index_t End>PLASMA_CONSTEXPR typename index_range<Begin, End>::type make_index_range()
	{
		return typename index_range<Begin, End>::type{};
	}
}