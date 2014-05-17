//object_array.hpp
//
// Copyright DtYaZsK 2014.
// Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at
//	http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include<array>
#include<memory>

namespace dyz_lib
{
    template<class BaseTy,std::size_t S>
	class object_array
    {
	std::array<std::unique_ptr<BaseTy>,S> elem_;
    public:
	object_array()=default;
	object_array(const object_array<BaseTy,S>&)=delete;
	object_array(object_array<BaseTy,S>&& ar):elem_()
	{
	    for(int i=0;i<S;++i)
		elem_[i] = std::move(ar.elem_[i]);
	}

	template<class Func>void for_each(Func func)
	{
	    for(auto& ptr : elem_)
	    {
		if(ptr)
		func(static_cast<BaseTy>(*ptr));
	    }
	}
	template<class Predicate>void remove_if(Predicate pred)
	{
	    for(auto& ptr : elem_)
	    {
		if(ptr && pred(static_cast<BaseTy>(*ptr)))
		    ptr.reset();
	    }
	}
	template<class T,class... Args>void emplace(Args&&... arg)
	{
	    for(auto& ptr : elem_)
	    {
		if(!ptr)
		    ptr = std::make_unique<T>(args...);
	    }
	}
    }
}
