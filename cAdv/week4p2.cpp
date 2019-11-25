#include<iostream>
#include<iomanip>
using namespace std;

//函数声明
int outputMat(const int mat[][100], int m, int n);

// 二维数组右上左下遍历
int main()
{
	int m, n;
	int mat[100][100];

    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    outputMat(mat, m, n);		

// good luck:)
    return 0;
}

int outputMat(const int mat[][100], int m, int n)
{
	const int *p = NULL;

	for (p = &mat[0][0]; p < &mat[0][n-1]; p++)  // 其实不必要用到指针，另外设一个k即可，用指针反而将问题复杂化。权当学习指针吧。
	{
        for (int i = 0, j = p - &mat[0][0]; i < m && j >= 0;  ++i, --j)
		{
            cout << mat[i][j] << endl; //
		}
	}

	for (p = &mat[0][n-1]; p <= &mat[m-1][n-1]; p += 100)
	{
        for (int i = (p - &mat[0][n-1]) / 100, j = n-1 ; i < m && j >= 0;  ++i, --j)
		{
            cout <<  mat[i][j] << endl;
		}
	}
	return 0;
}

