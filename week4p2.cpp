// week4p2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 奇偶排序1

#include <iostream>

using namespace std;

int main() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	// 首先，我们把奇数放到数组左边，偶数放到数组右边
	int l = 0, r = 9; //用左手和右手分别指向数组两端
	while (l <= r) {
		bool leftIsOdd = a[l] % 2 == 1;
		bool rightIsEven = a[r] % 2 == 0;
		if (leftIsOdd) {
			l++;
		}
		else if (rightIsEven) {
			r--;
		}
		else if (!leftIsOdd && !rightIsEven) {
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
	}
	// 对l左边（奇数部分）冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
	int start = 0, end = l;
	for (int i = start; i < end - 1; i++) {
		for (int j = start + 1; j < start + end - i; j++) {
			if (a[j - 1] > a[j]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	// 对l右边（偶数部分）冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
	start = l, end = 10;
	for (int i = start; i < end - 1; i++) {
		for (int j = start + 1; j < start + end - i; j++) {
			if (a[j - 1] > a[j]) {
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
