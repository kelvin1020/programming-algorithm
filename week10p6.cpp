#include<iostream>
using namespace std;

// 循环移动，精简算法！！  
int main()
{

    int vec[1000];
    int n, m;

    cin >> n >> m;

    m %= n;

    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    //前 n-m 位倒序
    for (int i = 0, j = n - m - 1 ; i < j; ++i, --j) // 通过异位运算连临时变量都不用
    {
        vec[i] = vec[i]^vec[j];
        vec[j] = vec[j]^vec[i];
        vec[i] = vec[i]^vec[j];        
    }

    //后 m 位倒序
    for (int i = n - m, j = n - 1 ; i < j; ++i, --j) // 通过异位运算连临时变量都不用
    {
        vec[i] = vec[i]^vec[j];
        vec[j] = vec[j]^vec[i];
        vec[i] = vec[i]^vec[j];        
    }    

    //全位倒序
    for (int i = 0, j = n - 1; i < j; ++i, --j) // 通过异位运算连临时变量都不用
    {
        vec[i] = vec[i]^vec[j];
        vec[j] = vec[j]^vec[i];
        vec[i] = vec[i]^vec[j];        
    } 

    //输出
    for (int i = 0; i < n; ++i)
    {
        cout << vec[i] << ' ';
    }

    cout << endl;

    return 0;
}

