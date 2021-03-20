#include <iostream>
using namespace std;

#if 0
class Solution{
public:
	//"ab-cd"
	string reverseOnlyLetters(string S){
		if (S.empty())
		{
			return S;
		}
		size_t left = 0, right = S.size() - 1;
		while (left < right)
		{
			//��ǰ�����ң���һ����Ч���ַ�
			while (left < right)
			{
				//if((S[left] >= 'a' && S[left] <= 'z' ) ||
				//   (S[left] >= 'A' && S[left] <= 'Z'))
				if(isalpha(S[left]))
					break;
				++left;
			}
			//C++
			//�Ӻ���ǰ�ң���һ����Ч���ַ�
			while (left < right)
			{
				if (isalpha(S[right]))
					break;
				--right;
			}
			//����
			if (left != right)
			{
				swap(S[left], S[right]);
				left++;
				right--;
			}
		}
		return S;
	}
};
int main()
{
	return 0;
}
#endif
#if 0
class Solution{
public:
	int firstUniqChar(string s){
		//1.ͳ��ÿ���ַ����ֵĴ���
		size_t count[256] = { 0 };
		for (auto e : s)
			count[e]++;
		//2.�ҵ���һ������һ�ε��ַ�
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (count[1 == s[i]])
				return i;
		}
		return -1;
	}
};
int main()
{
	return 0;
}
#endif
#if 0
class Solution{
public:
	bool IsValidChar(char ch)
	{
		if ((ch >= 'a' && ch <= 'z') ||
			(ch >= '0' && ch <= '9'))
		{
			return true;
		}
		return false;
	}
	bool isPalindrome(string s){
		if (s.empty())
			return true;
		//s�м���Сд��ĸ���д�д��ĸ---ͬ�⽫��д��ĸתСд��ĸ
		for (auto& e : s)
		{
			if (e >= 'A' && e <= 'Z')
				e += 32;
		}
		//s����ĸ���ڶ���Сд��
		size_t left = 0, right = s.size - 1;
		while (left < right)
		{
			//left����������һ�����ֻ���Сд��ĸ
			while (left < right)
			{
				if (IsValidChar(s[left]))
					break;
				++left;
			}
			//right����������һ�����ֻ���Сд����ĸ
			while (left < right)
			{
				if (IsValidChar(s[right]))
					break;
				--right;
			}
			if (left < right)
			{
				if (s[left] != s[right])
				{
					return false;
				}
				else
				{
					++left;
					--right;
				}
			}
		}
		return true;
	}
};
int main()
{
	return 0;
}
#endif
#if 1
class Solution{
public:
	//num1:"0"	num2:"0"
	string addStrings(string num1, string num2){
		//����num1λ���Ƚ϶�
		if (num1.size() < num2.size())
		{
			num1.swap(num2);
		}
		//num1�����ݵ�λ����num2��
		string strRet(num1.size() + 1, '0');
		
		char step = 0;

		for (int iLdx = num1.size() - 1, iRidx = num2.size() - 1;
			iLdx >= 0; --iLdx, --iRidx)
		{
			char ch = num1[iLdx] - '0';
			ch += num2[iRidx] - '0';
			if (ch >= 10)
			{
				step = 1;
				ch -= 10;
			}
			strRet[iLdx + 1] += ch;
		}
		}


};
int main()
{
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif