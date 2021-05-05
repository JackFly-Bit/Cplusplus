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
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T> Self;
		ListIterator(Node* pNode = nullptr)
			: _pNode(pNode)
		{ }

		//������Ҫ����ָ�����ƵĲ�����* ->
		T& operator*()
		{
			return _pNode->data;
		}

		T* operator->()
		{
			return &(operator*());
		}

		//������Ҫ�ܹ��ƶ�
		//ǰ��++/����++ ǰ��--/����--
		Self& operator++()
		{
			_pNode = _pNode->next;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->next;
			return temp;
		}

		Self& operator--()
		{
			_pNode = _pNode->prev;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->prev;
			return temp;
		}
		//������Ҫ�ܹ��Ƚ�
		bool operator!=(const Self& s)const
		{
			return _pNode != s._pNode;
		}

		bool operator==(const Self& s)const
		{
			return _pNode == s._pNode;
		}

		Node* _pNode;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T> iterator;

	//public:
	//	typedef T* iterator; ///˼���Ƿ���У�������

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

			Node* pCur = head->next;
			while (pCur != head)
			{
				push_back(pCur->data);
				pCur = pCur->next;
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
			return iterator(head->next);
		}

		iterator end()
		{
			return iterator(head);
		}

		/////////////////
		size_t size()const
		{
			size_t count = 0;
			Node* pCur = head->next;
			while (pCur != head)
			{
				++count;
				pCur = pCur->next;
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

		iterator insert(iterator pos, const T& data)
		{
			Node* newnode = new Node(data);
			Node* posNode = pos._pNode;

			newnode->next = posNode;
			newnode->prev = posNode->prev;
			posNode->prev = newnode;
			newnode->prev->next = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			if (pos == end())
				return pos;
			Node* posNode = pos._pNode;
			Node* pRet = posNode->next;

			posNode->prev->next = posNode->next;
			posNode->next->prev = posNode->prev;

			delete posNode;

			return iterator(pRet);
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = erase(first);
			}

			return last;
		}
		void clear()
		{
			erase(begin(), end());
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

#include <iostream>
using namespace std;

void TestList1()
{
	bite::list<int> L1;
	bite::list<int> L2(10, 5);

	int array[] = { 1, 2, 3, 4, 5 };
	bite::list<int> L3(array, array + sizeof(array) / sizeof(array[0]));

	bite::list<int> L4(L3);

	//������
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//ע�⣺�����Ҫ���Լ�д������֧�ַ�Χforѭ��
	//��ô�������б���Ҫʵ��begin/end�������Լ�������++����
	//��Χfor
	for (auto e : L3)
		cout << e << " ";
	cout << endl;
}

void TestList2()
{
	bite::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);

	cout << L.size() << endl;
	L.resize(10, 6);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.resize(4);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.push_front(0);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.pop_front();
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.erase(L.begin());
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.clear();
	if (L.empty())
	{
		cout << "ok" << endl;
	}
}