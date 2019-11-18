#include<iostream>
using namespace std;

int main()
{
    char s10[80];
    char s20[80];

    cin.getline(s10, 80);
    cin.getline(s20, 80);

    char s1[80] = {'\0'};
    char s2[80] = {'\0'};

    for (int i = 0; i < 80; ++i)
    {
        if ( s10[i] >= 65 && s10[i] <= 90 )
        {
            s1[i] = s10[i] + 32;
        }
        else
        {
            s1[i] = s10[i];
        }

        if ( s20[i] >= 65 && s20[i] <= 90 )
        {
            s2[i] = s20[i] + 32;
        }
        else
        {
            s2[i] = s20[i]; 
        }
    }


    int i = 0;
    char result;

    while (s1[i] != '\0' && (s1[i] == s2[i])){
        i++;
    }
    if (s1[i] > s2[i]) {
        result = '>';
    } else if (s1[i] < s2[i]) {
        result = '<';
    } else{
        result = '=';
    }

    cout << result << endl;

    return 0;
}

