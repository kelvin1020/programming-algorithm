#include<iostream>
#include<iomanip>
using namespace std;

//函数声明
int outputMat(const int mat[][100], int m, int n);
int calMat(const int mat[][100], int m, int n);

// 计算矩阵边缘元素之和
int main()
{
	int k, m, n;
	int mat[100][100];

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> m >> n;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
			}
		}
		// outputMat(mat, m, n);		
		cout << calMat(mat, m, n) << endl;
	}

// good luck:)
    return 0;
}

int outputMat(const int mat[][100], int m, int n)
{
	const int (*p)[100] = mat;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << *( *(p + i) + j);
		}
		cout << endl;
	}
	return 0;
}


int calMat(const int mat[][100], int m, int n)
{
	int part = 0;
	int total = 0;

	const int (*p)[100] = mat;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			total += *( *(p + i) + j);
		}
	}

	for (int i = 1; i < m-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			part += *( *(p + i) + j);
		}
	}
	return total - part;
}

