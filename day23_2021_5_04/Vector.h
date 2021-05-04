#pragma once

#include <assert.h>

namespace bite
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;

	public:
		vector()
			: start(nullptr)
			, finish(nullptr)
			, end_of_stroage(nullptr)
		{ }

		vector(int n, const T& data = T())
			: start(new T[n])
			, finish(start+n)
			, end_of_stroage(finish)
		{
			// memset(start, data, n);
			for (int i = 0; i < n; ++i)
				start[i] = data;
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			//distance(first, last);
			auto it = first;
			size_t count = 0;
			while (it != last)
			{
				++count;
				++it;
			}

			start = new T[count];
			finish = start;
			end_of_stroage = start + count;

			it = first;
			while (it != last)
			{
				*finish++ = *it++;
			}
		}

		vector(const vector<T>& v)
		{
			start = new T[v.capacity()];
			finish = start + v.size();
			end_of_stroage = start + v.capacity;

			for (size_t i = 0; i < v.size(); ++i)
			{
				start[i] = v[i];
			}
		}
		
		vector<T>& operator=(const vector<T>& v);


		~vector()
		{
			if (start)
			{
				delete[] start;
				start = finish = end_of_stroage = nullptr;
			}
		}
		/////////////////////////////////
		//迭代器
		iterator begin()
		{
			return start;
		}

		iterator end()
		{
			return finish;
		}

		iterator rbegin()
		{
			return end();
		}

		iterator rend()
		{
			return begin();
		}

		////////////////////////
		//capacity
		size_t size()const
		{
			return finish - start;
		}

		size_t capacity()const
		{
			return end_of_stroage - start;
		}

		bool empty()const
		{
			return start == finish;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				if (newsize > capacity())
					reserve(newsize);

				for (size_t i = oldsize; i < newsize; ++i)
					start[i] = data;
			}

			finish = start + newsize;
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				T* temp = new T[newcapacity];
				size_t count = size();
				if（start）
				{
					memcpy(temp, start, sizeof(T)*oldcapacity);
					delete[] start;
				}
				
				start = temp;
				finish = start + count;
				end_of_stroage = start + newcapacity;
			}
		}

		/////////////////////////////
		// 元素访问
		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}

		T& front()
		{
			return *start;
		}

		T& front()const
		{
			return *start;
		}

		T& back()
		{
			return *(finish - 1);
		}

		T& back()const
		{
			return *(finish - 1);
		}

		/////////////////////////
		//元素修改
		void push_back(const T& data)
		{
			if (size() == capacity())
				reserve(capacity() * 2 + 3);

			*finish++ = data;
		}

		void pop_back()
		{
			if (empty())
				return;

			--finish;
		}

		iterator insert(iterator pos, const T& data)
		{
			if (size() == capacity())
				reserve(2 * capacity() + 3);
			auto it = end();
			while (it != pos)
			{
				(*it) = *(it - 1);
				--it;
			}

			*pos = data;
			++finish;
			return pos;
		}
		
		iterator erase(iterator pos)
		{
			auto posnext = pos + 1;
			auto ret = pos;
			while (posnext != finish)
			{
				*pos++ = *posnext++;
			}

			--finish;
			return ret;
		}

		iterator erase(iterator first, iterator last)
		{
			finish = start;
		}

		void clear()
		{
			erase(begin(), end());
		}

		void swap(vector<T>& v)
		{
			std::swap(start, v.start);
			std::swap(finish, v.finish);
			std::swap(end_of_stroage, v.end_of_stroage);
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_stroage;
	};
}

#include<iostream>
using namespace std;

void TestVector1()
{
	bite::vector<int> v1;
	bite::vector<int> v2(10, 5);//int, int

	int array[] = { 1, 2, 3, 4, 5 };
	bite::vector<int> v3(array, array + sizeof(array)/sizeof(array[0]));

	bite::vector<int> v4(v3);

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	auto it = v4.begin();
	while (it != v4.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestVector2()
{
	bite::vector<int> v(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v[0] = 1;
	v.back() = 9;

	cout << v.front() << endl;
	cout << v.back() << endl;
}

void TestVector3()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.insert(v.begin(), 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.erase(v.begin());
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.pop_back();
	v.pop_back();
	v.pop_back();
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

void TestVector4()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(3);//3 9
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(7);//7 9
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(16, 8);//16 16
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

void TestVector5()
{}

void TestVector6()
{}

void TestVector7()
{}
