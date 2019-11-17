#include<iostream>
using namespace std;

int main()
{

    int n;
    int k;
    int list[1000];
    bool flag; 

    cin >> n >> k; 

    for (int i = 0; i < n; ++i)
    {
        cin >> list[i];
    }


    for (int i = 0; (i < n - 1) && (flag == false); ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (k == (list[i] + list[j]))
            {
                cout << "yes" << endl;
                flag = true;
                break;
            }
        }

        if (i == n - 2)
        {
            cout << "no" << endl;
        }
    }

    return 0;
}

