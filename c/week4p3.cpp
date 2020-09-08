// week4p3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 奇偶排序2

#include <iostream>

using namespace std;

int main() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	// 冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 10 - i; j++) {
			// 与刚才的冒泡排序不同，我们不只是通过较数字的大小决定顺序
			// 如果左边的为偶数，右边的为奇数，那么顺序也需要颠倒
			bool leftIsEven = a[j - 1] % 2 == 0;
			bool rightIsEven = a[j] % 2 == 0;
			if ((leftIsEven && !rightIsEven) ||
				(leftIsEven == rightIsEven && a[j - 1] > a[j])) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
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
