#include<iostream>
using namespace std;

int main(){

    int n;
    float distance[100];

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> distance[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if ( (distance[i] / 3. + 50.) < (distance[i] / 1.2) )
        {
            cout << "Bike" << endl;
        }
        else
        {
            if ( (distance[i] / 3. + 50.) == (distance[i] / 1.2) )
            {
                cout << "All" << endl;
            }

            else
            {
                cout << "Walk" << endl;     
            }
        }
    }

    return 0;
}