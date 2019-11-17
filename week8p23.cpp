#include<iostream>
using namespace std;

int main()
{

    int n;
    int k;

    while(cin >> n >> k)
    {
        
        float price = 200.;
        for (int i = 0; i < 20; ++i)
        {
            if ( (i+1) * n >= price)
            {
                cout << (i+1) << endl;
                break;   
            }

            price *= (1 + k / 100.);

            if (i == 19)
            {
                cout << "Impossible" << endl;  
            }

        }
    }


    return 0;
}

