// Copyright plasma 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/config.hpp>
#include<plasma/utility.hpp>
namespace plasma
{
	template<class T,class... Ts>struct tuple
	{
		typedef T value_type;
		typedef tuple<Ts...> next_type;
		T value;
		tuple<Ts...> next;
		PLASMA_CONSTEXPR tuple(T v, Ts... vs) :value(v), next(vs...){}
	};
	template<class T>struct tuple<T>
	{
		typedef T value_type;
		typedef void next_type;
		T value;
		PLASMA_CONSTEXPR tuple(T v) :value(v){}
	};

	template<index_t N, class T>struct tuple_element;
	template<index_t N, class T, class... Ts>struct tuple_element < N, tuple<T, Ts...> >
	{
		using type = typename tuple_element<(N - 1), tuple<Ts...>>::type;
	};
	template<class T,class... Ts>struct tuple_element<0, tuple<T,Ts...>>
	{
		using type = T;
	};

	namespace detail
	{
		template<index_t N, class T>struct get_impl
		{
			static PLASMA_CONSTEXPR typename tuple_element<N, T>::type& run(T& t)
			{
				return get_impl<(N - 1), typename T::next_type>::run(t.next);
			}
			static PLASMA_CONSTEXPR typename tuple_element<N, T>::type const& run(T const& t)
			{
				return get_impl<(N - 1), typename T::next_type>::run(t.next);
			}
			static PLASMA_CONSTEXPR typename tuple_element<N, T>::type&& run(T&& t)
			{
				return get_impl<(N - 1), typename T::next_type>::run(t.next);
			}
		};
		template<class T>struct get_impl< 0, T>
		{
			static PLASMA_CONSTEXPR typename T::value_type& run(T& t)
			{
				return t.value;
			}
			static PLASMA_CONSTEXPR typename T::value_type const& run(T const& t)
			{
				return t.value;
			}
			static PLASMA_CONSTEXPR typename T::value_type&& run(T&& t)
			{
				return static_cast<typename T::value_type&&>(t.value);
			}
		};
	}
	template<index_t N, class T>PLASMA_CONSTEXPR typename tuple_element<N, T>::type& get(T& t)
	{
		return detail::get_impl<N, T>::run(t);
	}
	template<index_t N, class T>PLASMA_CONSTEXPR typename tuple_element<N, T>::type const& get(T const& t)
	{
		return detail::get_impl<N, T>::run(t);
	}
	template<index_t N, class T>PLASMA_CONSTEXPR typename tuple_element<N, T>::type&& get(T&& t)
	{
		return detail::get_impl<N, T>::run(t);
	}

	template<class T>struct tuple_size
	{
		static PLASMA_SWITCH_CONSTEXPR index_t value = 0;
	};
	template<class... Ts>struct tuple_size<tuple<Ts...>>
	{
		static PLASMA_SWITCH_CONSTEXPR index_t value = sizeof...(Ts);
	};
	template<class T>PLASMA_CONSTEXPR index_t get_tuple_size(T)
	{
		return tuple_size<T>::value;
	}

	template<class... Ts>PLASMA_CONSTEXPR tuple<Ts...> make_tuple(Ts... args)
	{
		return tuple<Ts...>(args...);
	}
}