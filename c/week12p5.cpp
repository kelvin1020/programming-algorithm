
#include<iostream>
#include <cstring>

using namespace std;

// 字符串插入
int main()
{

    char str[11] = {'\0'};
    char substr[4] = {'\0'};



    while(cin.getline(str, 11, ' '))
    {
        
        cin.getline(substr, 4); 

        char ans[15] = {'\0'};
        int index = 0;
        int l1 = strlen(str);
        int l2 = strlen(substr);

        // cout << l1 << str << endl;
        // cout << l2 << substr <<endl;

        for (int i = 0; i < l1; ++i)
        {
            if (str[index] < str[i])
            {
                index = i;
            }
        }

        // cout << index << endl;

        for (int i = 0; i < l1 + l2; ++i)
        {
            if (i >= 0 && i <= index)
            {
                ans[i] = str[i];
            }
            else if (i >= index + 1 && i <= index + l2)
            {
                ans[i] = substr[i - index - 1];
            }
            else
            {
                ans[i] = str[i - l2];    
            }
        }

        cout << ans << endl;
    }

// good luck:)
    return 0;
}

