// Copyright plasma-effect 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include<plasma/utility.hpp>
#include<plasma/config.hpp>

#include<iterator>

namespace plasma
{
	struct increment_function
	{
		increment_function() = default;
		increment_function(increment_function const&) = default;
		template<class T>void operator()(T& value)
		{
			++value;
		}
	};
	template<class T,class F>struct range_t
	{
		T beg_;
		T end_;
		F func_;
		struct iterator :std::iterator<std::input_iterator_tag, T>
		{
			T value_;
			F func_;
			iterator(T beg, F func) :value_(beg),func_(func){}
			iterator& operator++()
			{
				func_(value_);
				return *this;
			}
			iterator operator++(int)
			{
				auto ret = *this;
				func_(value_);
				return ret;
			}
			T const& operator*()
			{
				return value_;
			}
			bool operator==(iterator ite)
			{
				return value_ == ite.value_;
			}
			bool operator!=(iterator ite)
			{
				return value_ != ite.value_;
			}
		};
		iterator begin()
		{
			return iterator(beg_, func_);
		}
		iterator end()
		{
			return iterator(end_, func_);
		}
	};
	template<class T, class F>range_t<T,F> range(T beg, T end, F func)
	{
		return range_t < T, F > {beg, end, func};
	}
	template<class T>range_t<T, increment_function> range(T beg, T end)
	{
		return range_t < T, increment_function > {beg, end, increment_function()};
	}
}