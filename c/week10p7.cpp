#include<iostream>
using namespace std;

// 不排序计算中位数
int main()
{

    int vec[15000] = {0};
    int ans[15000] = {0};    
    int n, flag, half;
    int count = 0;

    while(cin >> n)
    {
        if (n == 0)  // 如果0，则输出结果，结束循环
        {
            for (int i = 0; i < count; ++i)
            {
                cout << ans[i] << endl;
            }

            break;
        }

        for (int i = 0; i < n; ++i) //输入数组
        {
            cin >> vec[i];
        }

        //计算中位数 - 冒泡排序
        do
        {
            flag = 0;
            for (int i = 0; i < n - 1; ++i)
            {
                if (vec[i] > vec[i+1])
                {
                    vec[i] = vec[i]^vec[i+1];
                    vec[i+1] = vec[i+1]^vec[i];               
                    vec[i] = vec[i]^vec[i+1];
                    ++flag;
                }
            }

        }while(flag != 0);

        //奇数偶数分情况
        if (n % 2 == 0)
        {
            half = (vec[(n - 2) / 2] + vec[n / 2]) / 2;        
        }
        else
        {
            half = vec[(n - 1) / 2];
        }

        //存储结果
        ans[count] = half;

        //计数加1
        ++count;
    }

    return 0;
}

