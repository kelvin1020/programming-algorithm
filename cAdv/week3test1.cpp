#include<iostream>
using namespace std;

//函数声明
int count(int m, int n);


// 放苹果
int main()
{
    int apples, plates;
    cin >> apples >> plates;
    cout << count(apples, plates) << endl;
// good luck:)
    return 0;
}


int count(int m , int n)
{
    if (m <= 1|| n <= 1) return 1;
    if(m < n)
        return count(m, m);
    else
        return count(m, n-1) + count(m-n, n);
}