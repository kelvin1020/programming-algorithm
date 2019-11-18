#include<iostream>
using namespace std;

int main()
{
    char s[512];    
    cin.getline(s, 512);

    bool flag = false;
    int length = 0;
    int index = 0;
    int temp = 0;


    for (int i = 0; s[i] != '\0'; ++i)
    {

        if ((s[i] == ' ') || (s[i] == '.'))
        {
            if (temp < length)
            {
                temp = length;    
                index = i - temp;
                // cout << temp << endl;
            }
            length = 0;    
            flag = false;
        }
        else
        {
            flag = true;
        }

        if (flag == true)
        {
            length++;
        }
    }

    for (int i = index; i < index + temp; ++i)
    {
        cout << s[i];     
    }
    cout  << endl;

    return 0;
}

