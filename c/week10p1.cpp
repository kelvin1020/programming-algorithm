#include<iostream>
using namespace std;

int main()
{
    char s[80];
    int ans[5] = {0};

    cin.getline(s, 80);


    for (int i = 0; i < 80; ++i)
    {
        switch(s[i])
        {
            case 'a':ans[0]++; break;
            case 'e':ans[1]++; break;
            case 'i':ans[2]++; break;
            case 'o':ans[3]++; break;
            case 'u':ans[4]++; break;                                   
        }
    }


    for (int i = 0; i < 5; ++i)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

