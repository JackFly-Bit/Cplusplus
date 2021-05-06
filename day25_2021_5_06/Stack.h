#pragma once

#include <vector>

//���⣺stackΪʲôû�е�������
//����Ҫ��stack�е����ݽ��б���---ֻ������һ�˽��в���
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