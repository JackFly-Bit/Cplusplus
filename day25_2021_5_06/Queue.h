#pragma once

#include <list>

namespace bite
{
	template<class T>
	class queue
	{
	public:
		queue()
		{ }

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			if (_con.empty())
				return;

			_con.pop_front();
		}

		T& front()
		{
			return _con.front();
		}

		const T& front()const
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}

		const T& back()const
		{
			return _con.back();
		}
		
		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}

	private:
		std::list<T> _con;
	};
}