#include<iostream>
#include <cstring>
using namespace std;

//函数声明
int cal(int n);

// 角谷猜想
int main()
{
	int n;
	cin >> n;

	cal(n);

// good luck:)
    return 0;
}

int cal(int n)
{
	if (n == 1)
	{
		cout << "End" << endl;		
	}

	else
	{
		if (n % 2 == 1)
		{
			cout << n << '*' << 3 << '+' << 1 << '=' << n * 3 + 1 << endl;	
			cal(n * 3 + 1);
		}

		else
		{
			cout << n << '/' << 2 << '=' << n / 2 << endl;	
			cal(n / 2);
		}

	}
	
	return 0;
}


