#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

//函数声明
int sortmat(int mat[][2], int n);
int findmax(int mat[][2], int n);

// 寻找平面上极大的点

int main()
{
    int n;
    int mat[100][2];
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> mat[i][0] >> mat[i][1];
    }

    sortmat(mat, n);
    findmax(mat, n);
    
// good luck:)
    return 0;
}


int sortmat(int mat[][2], int n)
{
    int temp = 0;
    for(int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if (mat[i][0] > mat[j][0])
            {
                temp = mat[i][0];
                mat[i][0] = mat[j][0];
                mat[j][0] = temp;
        
                temp = mat[i][1];
                mat[i][1] = mat[j][1];
                mat[j][1] = temp;
            }
        }
    }
    return 0;
}

int findmax(int mat[][2], int n)
{
    bool flag = true;
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                if (mat[i][0] <= mat[j][0] && mat[i][1] <= mat[j][1])
                {
                    flag = false;
                }
            }
        }

        if (flag)
        {
            cout << '(' << mat[i][0] << ',' << mat[i][1] << ')';

            if (i != n-1)
            {
                cout << ',';
            }
            else
            {
                cout << endl;
            }
        }
        flag = true;
    }   
    return 0;
}


