// week7p23.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
using namespace std;

int main()
{
	int n;
    cin >> n;

    int k;
    cin >> k;

	int a[100];
	for (int i = 0; i < n; ++i)
	 {
	 	cin >> a[i];
	 } 

	int max[100];
	for (int i = 0; i < n; ++i)
	 {
	 	max[i] = 0;
	 } 


	int maxindex[100];
	for (int i = 0; i < n; ++i)
	 {
	 	maxindex[i] = -1;
	 } 


	int temp;
	int tempindex;
	int b;

	for (int j = 0; j < k; ++j)
	{
		if (j == 0)
		{
			temp = a[0];
			tempindex = 0; 
			for (int i = 0; i < n; ++i)
			{
				if (a[i] > temp)
				{
					temp = a[i];
					tempindex = i;
				}
			}
			max[0] = temp;
			maxindex[0] = tempindex;
		}

		else
		{
			temp = a[0];
			tempindex = 0; 
			for (int i = 0; i < n; ++i)
			{
				if (a[i] > temp && a[i] < max[j-1])
				{
					temp = a[i];
					tempindex = i;
				}
			}
			max[j] = temp;
			maxindex[j] = tempindex;
		}
	}

	b = max[k - 1];
    cout << b;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
