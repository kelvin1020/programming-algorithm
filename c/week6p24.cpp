// week6p24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;
int main() {
	int number[6];              //正整数数组
	int min_even = -1;          //最小偶数，初始值-1，为了标记未记录
	int max_odd = -1;           //最大奇数，初始值-1，为了标记未记录
	int ans;                    //输出答案
	// 输入6个整数
	cin >> number[0] >> number[1] >> number[2] >> number[3] >> number[4] >> number[5];

	
	// 遍历数组，求最最大奇数 和最小偶数
	for (int i = 0; i < 6; ++i)
	{
		if ((number[i]%2)==0)          //判断是否偶数？
		{
			if (min_even == -1)        //判断min_even 是否被赋正值
			{
				min_even = number[i];
			}

			if (min_even > number[i]) //判断是否最小偶数
			{
				min_even = number[i];
			}
		}
		
		else 
		{
			if (max_odd == -1)        //判断是否奇数？
			{
				max_odd = number[i];  //判断max_odd 是否被赋正值
			}

			if (max_odd < number[i])  //判断是否最大奇数
			{
				max_odd = number[i];
			}
		}
	}

	ans = max_odd - min_even;         
	if (ans < 0)                      //判断是否负数
	{
		ans = - ans;
	}

	//输出最高成绩
	cout << ans;
	
	return 0;
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
