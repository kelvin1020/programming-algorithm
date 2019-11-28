#include<iostream>
#include<iomanip>
using namespace std;

//函数声明
bool isDiv(int m);
bool isk3(int m, int k);

// 含k个3的数
int main()
{
	int m, k;
	cin >> m >> k;

    if ( isDiv(m) && isk3(m, k) )
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

// good luck:)
    return 0;
}

bool isDiv(int m)
{
    if( m % 19 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isk3(int m, int k)
{
    int count = 0;

    if (m / 10000 == 3)
    {
        count++;
    }
    m = m - (m / 10000) * 10000;

    if (m / 1000 == 3)
    {
        count++;
    }
    m = m - (m / 1000) * 1000;

    if (m / 100 == 3)
    {
        count++;
    }
    m = m - (m / 100) * 100;

    if (m / 10 == 3)
    {
        count++;
    }
    m = m - (m / 10) * 10;

    if (m / 1 == 3)
    {
        count++;
    }

    if (count == k)
    {
        return true;
    }
    else
    {
        return false;
    }
}