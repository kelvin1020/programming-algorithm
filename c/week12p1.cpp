#include<iostream>
using namespace std;

// 判断某年是不是闰年 
int main()
{
    int y;

    cin >> y;

    if (y % 4 == 0 && y % 100 != 0)
    {
        cout << "Y" << endl;        
    }
    else if (y % 400 == 0)
    {
        cout << "Y" << endl;       
    }
    else
    {
        cout << "N" << endl;        
    }

    return 0;
}


