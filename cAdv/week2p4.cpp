
#include<iostream>
#include <iomanip>
using namespace std;

//函数声明

int inputData(int data[]);
bool isLeapYear(int year);
int outputData(int y, int m, int d);

// Tomorrow never knows
int main()
{

    int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int lymdays[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int data[3];
    int y, m, d;

    //输入数据
    inputData(data);

    y = data[0];
    m = data[1];
    d = data[2];

    // + 1 d 
    ++d;

    if (isLeapYear(y))
    {
        if (d > lymdays[m])
        {
            ++m;
            d = 1;
        }

        if (m > 12)
        {
            ++y;
            m = 1;
        }

    }

    else
    {
        if (d > mdays[m])
        {
            ++m;
            d = 1;
        }

        if (m > 12)
        {
            ++y;
            m = 1;
        }
    }




    //输出数据
    outputData(y, m, d);

// good luck:)
    return 0;
}




int inputData(int data[])
{
    char a, b;
    cin >> data[0] >> a >> data[1] >> b >> data[2];
    return 0;
}


bool isLeapYear(int y)
{
    if (y % 4 == 0 && y % 100 != 0)
    {
        return true;        
    }
    else if (y % 400 == 0)
    {
        return true;          
    }
    else
    {
        return false;          
    }
}


int outputData(int y, int m, int d)
{
    cout << y << '-';
    cout << setfill('0') << setw(2) << m << '-';
    cout << setfill('0') << setw(2) << d;
    cout << endl;
    return 0;
}


