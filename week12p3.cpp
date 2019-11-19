#include<iostream>
#include <iomanip>
#include <cmath> 


using namespace std;

// 最远距离
int main()
{

    int n;
    double dis = 0;    
    double temp = 0;    
    double mat[(int) 1e4][2] = {0.};

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            temp = sqrt( (mat[i][0] - mat[j][0]) * (mat[i][0] - mat[j][0]) +\
                         (mat[i][1] - mat[j][1]) * (mat[i][1] - mat[j][1]) );
            if (temp > dis)
            {
                dis = temp;
            }
        }
    }

    cout << fixed << setprecision(4) << dis << endl;
    

// good luck:)
    return 0;
}

