#pragma once

#include <vector>

//问题：stack为什么没有迭代器？
//不需要对stack中的数据进行遍历---只能在其一端进行操作
namespace bite
{
	template<class T>
	class stack
	{
	public:
		stack()
		{ }

		void push(const T& data)
		{
			Con.push_back(data);
		}

		void pop()
		{
			if (Con.empty())
				return;

			Con.pop_back();
		}

		T& top()
		{
			return Con.back();
		}

		const T& top()const
		{
			return Con.back();
		}

		size_t size()const
		{
			return Con.size();
		}

		bool empty()const
		{
			return Con.empty();
		}

	private:
		std::vector<T> Con;

	};
}