#include<iostream>
using namespace std;

int main()
{

    int n;
    int a, b;

    cin >> n;

    for (int i = 10; i < n; ++i)
    {
        a = i / 10;
        b = i % 10;

        if (i % (a + b) == 0)
        {
            cout << i << endl;        
        }

    }

    return 0;
}

