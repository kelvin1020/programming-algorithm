
#include<iostream>
#include <cmath>
using namespace std;

//函数声明

int rowExchange(int i, int j, float data[][5]);
int classData(float data[][5], float fmax, float fmin, int n);
// int outputData(float data[][5], int n);
int outputResult(float data[][5], int n);

// 细菌实验分组
int main()
{
    int n;
    float data[100][5] = {0};
    int flag;
    //输入
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }


    //计算繁殖率
    for (int i = 0; i < n; ++i)
    {
        data[i][3] = (data[i][2] - data[i][1]) / data[i][1];
    }


    // 根据繁殖率冒泡法排序，从小到大

    do
    {
        flag = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (data[i][3] > data[i+1][3])
            {
                rowExchange(i, i+1, data);
                ++flag;
            }
        }

    }while(flag != 0);

    //分类 大 -- 1，小 --0
    classData(data, data[n-1][3], data[0][3], n);

    //输出
    // outputData(data, n);
    outputResult(data, n);

// good luck:)
    return 0;
}

int rowExchange(int i, int j, float data[][5])
{
    float temp[1][5] = {};

    if (i != j)
    {
        for (int k = 0; k < 5; ++k)
        {
            temp[0][k] = data[i][k];
            data[i][k] = data[j][k];
            data[j][k] = temp[0][k];
        }

    }
    return 0;
}


// 用于交换数组行，不可行
// int VarExchange(int a, int b)
// {
//     a = a ^ b;
//     b = b ^ a;
//     a = a ^ b;
//     return 0;
// }

int classData(float data[][5], float fmax, float fmin, int n)
{

    for (int i = 0; i < n; ++i)
    {
        if ( abs(data[i][3] - fmax) < abs(data[i][3] - fmin) )
            data[i][4] = 1;

        else
            data[i][4] = 0;            
    }
    return 0;
}


int outputData(float data[][5], int n)
{
  
    for (int i = 0; i < n; ++i)
    {
        cout << data[i][0] << ' ' << data[i][1] << ' ' << data[i][2] << \
        ' ' << data[i][3] << ' ' << data[i][4] << endl;
    }


    cout << endl;

    return 0;
}

int outputResult(float data[][5], int n)
{
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i)
    {
        a += data[i][4];
    }

    b = n - a;

    //输出a
    cout << a << endl;
    for (int i = 0; i < n; ++i)
    {
        if (data[i][4] == 1)
        {
            cout << data[i][0] << endl;
        }

    }

    //输出b
    cout << b << endl;
    for (int i = 0; i < n; ++i)
    {
        if (data[i][4] == 0)
        {
            cout << data[i][0] << endl;
        }

    }
    return 0;
}
