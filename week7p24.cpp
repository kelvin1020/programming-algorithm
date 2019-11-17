// week7p24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
using namespace std;

int main()
{
	int n;
    cin >> n;

    int an=0, bn=0, cn=0, dn=0, en=0, fn=0;


    if (n >= 100 && n < 1000)
 	{
 		an  = n / 100;
 		n  -= an * 100;
 	}

 	if (n >= 50 && n < 100)
	{
 		bn  = n / 50;
 		n  -= bn * 50;
 	}
		
	if (n >= 20 && n < 50) 
	{					
 		cn  = n / 20;
 		n  -= cn * 20;
	}

	if (n >= 10 && n < 20) 
	{					
 		dn  = n / 10;
 		n  -= dn * 10;
	}

	if (n >= 5 && n < 10) 
	{					
 		en  = n / 5;
 		n  -= en * 5;
	}

	if (n >= 1 && n < 5) 
	{					
 		fn  = n / 1;
	}
				
    cout << an << endl;
    cout << bn << endl;
    cout << cn << endl;
    cout << dn << endl;
    cout << en << endl;
    cout << fn << endl;
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
