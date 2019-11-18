#include<iostream>
#include <iomanip>
using namespace std;

int main()
{

    int n, ans = 0;
    int mat[100][100];

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 1; j < n - 1; ++j)
        {
            if (mat[i][j-1] - mat[i][j] >= 50 && mat[i][j+1] - mat[i][j] >= 50 && mat[i+1][j] - mat[i][j] >= 50 && mat[i-1][j] - mat[i][j] >= 50 )
            {
                ++ans;
            }
        }   
    }

    cout << ans << endl;
    return 0;
}


