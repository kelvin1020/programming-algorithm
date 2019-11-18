#include<iostream>
using namespace std;

// 循环移动，精简算法！！  
int main()
{

    bool vec[10001] = {false};
    int  mat[100][2] = {0};

    int l, m;
    int count = 0;

    cin >> l >> m;

    //种树
    for (int i = 0; i < l + 1; ++i)
    {
        vec[i] = true;
    }


    //地铁区域坐标输入，
    for (int i = 0; i < m; ++i)
    {
        cin >> mat[i][0] >> mat[i][1];
    }


    //移树
    for (int i = 0; i < m; ++i)
    {
        
        for (int k = mat[i][0]; k < mat[i][1] + 1; ++k)
        {
            vec[k] = false;
        }

    }

    //输出
    for (int i = 0; i < l + 1; ++i)
    {
        if (vec[i] == true)
        {
            ++count;
        }        
    }

    cout << count << endl;

    return 0;
}


