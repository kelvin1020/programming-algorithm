
#include<iostream>
#include <cstring>

using namespace std;

//函数声明
int findIndex(int n, int x[]);

// 寻找下标
int main()
{

    int n, ans;
    int x[100] = {0};

    //输入数组
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x[i]; 
    }

    //寻找下标
    ans = findIndex(n, x);

    if (ans >= 0)
    {
        cout << ans << endl;   
    }
    else
    {
        cout << 'N' << endl;        
    }

// good luck:)
    return 0;
}


int findIndex(int n, int x[])
{
    int index = -1;

    for (int i = 0; i < n; ++i)
    {
        if (x[i] == i)
        {
            index = i;
            break;
        }
    }

    return index;
}