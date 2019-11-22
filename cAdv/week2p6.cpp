
#include<iostream>
using namespace std;

//函数声明
int evolveData(char data[][100], int n);
int infect(int i, int j, char data[][100], int n);
int outputData(char data[][100], int n);
int outputResult(char data[][100], int n);

// 流感传染
int main()
{
    int n;
    char data[100][100] = {'#'};
    int m;

    //输入
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> data[i][j];    
        }
    }

    cin >> m;

    // outputData(data, n);
    // outputResult(data, n);

    //演化
    for (int i = 0; i < m - 1; ++i)
    {
        evolveData(data, n);     
        // outputData(data, n);
        // outputResult(data, n);
    }

    //输出
    outputResult(data, n);

// good luck:)
    return 0;
}



int evolveData(char data[][100], int n)
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (data[i][j] == '@')
            {
                infect(i, j+1, data, n);
                infect(i, j-1, data, n);
                infect(i-1, j, data, n);
                infect(i+1, j, data, n);
            }
            
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (data[i][j] == '?')
            {
                data[i][j] = '@';
            }
            
        }
    }

    return 0;
}

int infect(int i, int j, char data[][100], int n)
{
    if (i >= 0 && i < n &&  j >= 0 && j < n)
    {
        if (data[i][j] == '.')
        {
            data[i][j] = '?'; // 预备感染
        }
    }
}



int outputData(char data[][100], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


int outputResult(char data[][100], int n)
{
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (data[i][j] == '@')
            {
                count++;  
            }
        }
    }
    cout << count << endl;
    return 0;
}
