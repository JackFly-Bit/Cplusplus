#include <iostream>
using namespace std;

#if 0

//typedef double DataType;

#include <assert.h>

//��ģ��--��������������
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{ }

	SeqList(const SeqList<T>& s);
	SeqList<T>& operator = (const SeqList<T>& s);

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_capacity = 0;
			_size = 0;
		}
	}
	///////////////////////////////
	//
	size_t size()const
	{
		return _size;
	}

	size_t capacity()const
	{
		return _capacity;
	}

	bool empty()const
	{
		return 0 == _size;
	}

	//////////////////////////////
	void push_back(const T& data);
	//{
	//	//�ռ��㹻
	//	_CheckCapacity();
	//	_array[_size++] = data;
	//}

	void pop_back()
	{
		if (empty())
		{
			return;
		}
		--_size;
	}

	/////////////////////////////////

	T& operator[] (size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[] (size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

	////////////////////////////////
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void  SeqList<T>::push_back(const T& data)
{
	// _CheckCapacity();

	_array[_size++] = data;
}

int main()
{
	SeqList<int> s1;
	s1.push_back(1);
	s1.push_back(2);
	s1.push_back(3);
	s1.push_back(4);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	cout << s1[0] << endl;

	s1[0] = 10;
	cout << s1[0] << endl;

	s1.pop_back();
	s1.pop_back();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	SeqList<double> s2;
	s2.push_back(1.0);
	s2.push_back(2.0);
	s2.push_back(3.0);

	const SeqList<int> s3;
	//s3[0];
	return 0;
}
#endif
#if 0
int main()
{
	const char* p = "hello world";
	//*p = 'H';

	//�ַ���
	char str1[] = "hello world";

	//�ַ�����
	char str2[] = { 'b', 'i', 't' };
	return 0;
}
#endif
#if 0
int main()
{
	string s1; //����һ���յ��ַ���-->'\0'
	string s2("hello");
	string s3(10, 'a');//string(size_t n, char ch);
	string s4(s2);
	string s5(s2, 0, 3);
	string s6("world", 4);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	return 0;
}
#endif
#if 0
//����λ��Ԫ�صķ��ʲ���
#include <assert.h>
int main()
{
	string s("hello world");
	cout << s[0] << endl;
	s[0] = 'H';
	cout << s << endl;

	//ע�⣺�±겻��Խ�磬�����ܳ�����ЧԪ�ظ���
	cout << s.length << endl;

	//assert(0);
	//��operator[]��ʹ�õ�ʱassert������Ƿ�Խ���
	cout << s[13] << endl;
	return 0;
}
#endif
#if 0
#include <assert.h>
int main()
{
	string s("hello world");
	cout << s.at(0) << endl;
	s.at(0) = 'H';
	cout << s << endl;

	//ע�⣺�±겻��Խ�磬�����ܳ�����ЧԪ�ظ���
	cout << s.length << endl;

	//assert(0);
	//at:�ڲ������쳣����������Ƿ�Խ�� out_of_range
	cout << s.at(13) << endl;
	return 0;
}
#endif
#if 1
int main()
{
	string s("hello world");
	for (size_t i = 0; i < s.length; ++i)
	{
		cout << s[i];
	}
	cout << endl;

	for (auto e : s)
		cout << e;
	cout << endl;

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
