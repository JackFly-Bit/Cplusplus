#include <iostream>
using namespace std;



int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		// ....
	}

	// �ڿռ��д洢����


	free(p);
	return 0;
}