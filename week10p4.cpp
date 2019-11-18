#include<iostream>
#include <iomanip>
using namespace std;

int main()
{

    int mat[5][5];
    int n, m;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> mat[i][j];
        }
    }

    cin >> n >> m;

    if(n < 0 || n >= 5 || m < 0 || m >= 5)
    {
        cout<< "error" << endl;
    }

    else
    {
        for (int j = 0; j < 5; ++j) // 按位异或交换值
        {
            mat[n][j] = mat[n][j]^mat[m][j];
            mat[m][j] = mat[m][j]^mat[n][j];
            mat[n][j] = mat[n][j]^mat[m][j];            
        }

        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cout << setw(4) << mat[i][j];
            }
            cout << endl;
        }
    }        

    return 0;
}

