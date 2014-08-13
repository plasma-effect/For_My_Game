// Copyright plasma-effect 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include<plasma/utility.hpp>
#include<plasma/config.hpp>

#include<functional>
namespace plasma
{
	template<class T>class properties
	{
		T value_;
		std::function<void(T&,T const&)> set_;
		std::function<T const&(T&)> get_;
	public:
		template<class... Ts>properties(std::function<void(T&,T const&)> set, std::function<T const&(T&)> get, Ts&&... args) 
			:value_(args...), set_(set), get_(get){}
		properties(properties<T> const&) = default;

		properties<T>& operator=(T const& arg)
		{
			set_(value_, arg);
			return *this;
		}
		operator T()
		{
			return get_(value_);
		}
	};
}