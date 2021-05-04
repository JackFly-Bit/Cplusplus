#pragma once

namespace bite
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& x = T())
		: prev(nullptr)
		, next(nullptr)
		, data(x)
		{}

		ListNode<T>* prev;
		ListNode<T>* next;
		T data;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;

	public:
		typedef T* iterator; ///思考是否可行？

	public:
		list()
		{
			CreatHead();
		}

		list(int n, const T& data = T())
		{
			CreatHead();
			for (int i = 0; i < n; ++i)
				push_back(data);

		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreatHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& L)
		{
			CreatHead();

			auto it = L.begin();
			while (it != L.end())
			{
				push_back(*it);
				++it;
			}
		}

		list<T>& operator = (const list<T>& L);
		~list()
		{
			clear();
			delegate head;
			head = nullptr;
		}

		////////////////////////
		iterator begin()
		{
			return head->next;
		}

		iterator end()
		{
			return head;
		}

		/////////////////
		size_t size()const
		{
			size_t count = 0;
			auto it = begin();
			while (it != end())
			{
				count++;
				++it;
			}

			return count;
		}

		bool empty()const
		{
			return head == head->next;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				for (size_t i = newsize; i < oldsize; ++i)
					pop_back();
			}
			else
			{
				for (size_t i = oldsize; i < newsize; ++i)
					push_back(data);
			}
		}
		////////////////////////
		void push_back(const T& data)
		{
			insert(end(), data);
		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const T& data)
		{
			insert(begin().data);
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& data);
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void clear()
		{
			erase(first, last);
		}
	private:
		void CreatHead()
		{
			head = new Node;
			head->next = head;
			head->prev = head;
		}

	private:
		Node* head;
	};
}