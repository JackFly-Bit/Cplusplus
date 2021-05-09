#pragma once

#include <vector>

namespace bite
{
	template<class T, class Container = std::vector<T>, class Com = std::less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
			: _con(first, last)
		{
			//将_con中的元素调整成堆

			//1.找调整的位置
			int size = _con.size();
			int root = ((size - 2) >> 1);
			for (; root >= 0; --root)
				_AdjustDown(root);
		}

		void push(const T& data)
		{
			_con.push_back(data);
			int child = _con.size() - 1;
			int parent = ((child - 1) >> 1);

			while (child)
			{
				if (Com()(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = ((child - 1) >> 1);
				}
				else
				{
					return;
				}
			}
		}

		void pop()
		{
			if (empty())
				return;

			std::swap(_con.front(), _con.back());
			_con.pop_back();

			_AdjustDown(0);
		}

		const T& top()const
		{
			return _con.front();
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
		void _AdjustDown(int parent)
		{
			//默认情况下：child标记左孩子
			size_t child = parent * 2 + 1;

			while (child < _con.size())
			{
				//找左右孩子中较大的孩子
				Com com;
				if (child + 1 < _con.size() && com(_con[child], _con[child]))
					child += 1;

				//用较大的孩子和双亲比较
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					return;
				}
			}
		}

	private:
		Container _con;
	};
}

#include <iostream>
using namespace std;

void TestMyPriorityQueue1()
{
	bite::priority_queue<int> q;
	q.push(3);
	q.push(7);
	q.push(1);
	q.push(4);
	q.push(2);
	q.push(6);
	q.push(5);

	cout << q.size() << endl;
	cout << q.top() << endl;

	q.pop();
	cout << q.size() << endl;
	cout << q.top() << endl;
}

template<class T>
class Greater
{
public:
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

void TestMyPriorityQueue2()
{
	bite::priority_queue<int, vector<int>, Greater<int>> q;
	q.push(3);
	q.push(7);
	q.push(1);
	q.push(4);
	q.push(2);
	q.push(6);
	q.push(5);

	cout << q.size() << endl;
	cout << q.top() << endl;

	q.pop();
	cout << q.size() << endl;
	cout << q.top() << endl;
}