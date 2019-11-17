#include<iostream>
using namespace std;

int main()
{

    int n;
    int k;
    int list[1000];
    int flag = 0;

    cin >> n >> k; 

    for (int i = 0; i < n; ++i)
    {
        cin >> list[i];
    }


    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (k == (list[i] + list[j]))
            {
                ++flag;
            }
        }  
    }

    if (flag > 0)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }


    return 0;
}

