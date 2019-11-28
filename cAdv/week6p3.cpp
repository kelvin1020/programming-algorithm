#include<iostream>
#include<iomanip>
using namespace std;

//函数声明

int markData(int data[][20], int m , int n);

// 寻找山顶
int main()
{
	int m, n;
	int data[50][20] = {0};
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
        {
            cin >> data[i][j];
        }
	}

    markData(data, m, n);

// good luck:)
    return 0;
}

int markData(int data[][20], int m , int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
        {   
            if (i >= 1 && i <= m-2 && j >= 1 && j <= n-2)
            {
                if (data[i][j] >= data[i-1][j] && data[i][j] >= data[i+1][j] && data[i][j] >= data[i][j-1] && data[i][j] >= data[i][j+1])
                {
                    cout << i << " " << j << endl;
                }
            }
            else if(i == 0 && j == 0)
            {
                if (data[i][j] >= data[i+1][j] && data[i][j] >= data[i][j+1])
                {
                    cout << i << " " << j << endl;
                }
            }
            else if (i == 0 && j < n - 1)
            {
                if (data[i][j] >= data[i+1][j] && data[i][j] >= data[i][j-1] && data[i][j] >= data[i][j+1])
                {
                    cout << i << " " << j << endl;
                }
            }
            else if (i == 0 && j == n - 1)
            {
                if (data[i][j] >= data[i+1][j] && data[i][j] >= data[i][j-1])
                {
                    cout << i << " " << j << endl;
                }
            }

            else if (i > 0 && i < m - 1 && j == 0)
            {
                if (data[i][j] >= data[i-1][j] && data[i][j] >= data[i+1][j] && data[i][j] >= data[i][j+1])
                {
                    cout << i << " " << j << endl;
                }
            }            
            else if (i > 0 && i < m - 1 && j == n-1)
            {
                if (data[i][j] >= data[i-1][j] && data[i][j] >= data[i+1][j] && data[i][j] >= data[i][j-1])
                {
                    cout << i << " " << j << endl;
                }
            }
            else if (i == m - 1 && j == 0)
            {
                if (data[i][j] >= data[i-1][j] && data[i][j] >= data[i][j+1])
                {
                    cout << i << " " << j << endl;
                }
            }
            else if (i == m - 1 && j > 0 && j < n - 1)
            {
                if (data[i][j] >= data[i-1][j] && data[i][j] >= data[i][j-1] && data[i][j] >= data[i][j+1])
                {
                    cout << i << " " << j << endl;
                }
            }
            else if (i == m - 1 && j == n - 1)
            {
                if (data[i][j] >= data[i-1][j] && data[i][j] >= data[i][j-1])
                {
                    cout << i << " " << j << endl;
                }
            }
        }
	}

    return 0;
}
