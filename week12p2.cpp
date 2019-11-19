#include<iostream>
using namespace std;

// 能被3 5 7 整除的数
int main()
{

    int n;
    
    while(cin>>n)
    {
        bool three = false;
        bool five = false;
        bool seven = false;

        if (n % 3 == 0)
        {
            three = true;
            cout << 3 << " ";                         
        }

        if (n % 5 == 0)
        {
            five = true;
            cout << 5 << " ";       
        }

        if (n % 7 == 0)
        {
            seven = true;
            cout << 7 << " ";  
        }


        if (three == false && five == false && seven == false)
        {
            cout << 'n';         
        }

        cout << endl;
    }

// good luck:)
    return 0;
}

