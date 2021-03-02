#include <iostream>
using namespace std;



int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		// ....
	}

	// 在空间中存储数据


	free(p);
	return 0;
}