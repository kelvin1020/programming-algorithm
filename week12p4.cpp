#include<iostream>
using namespace std;

// 简单计算器
int main()
{

    int a;
    int b;
    char c;
    while(cin >> a >> b >> c)
    {
        switch(c)
        {
            case '+': cout << a + b << endl; break;
            case '-': cout << a - b << endl; break;
            case '*': cout << a * b << endl; break;
            case '/': if (b == 0) cout << "Divided by zero!" << endl; break;
                      cout << a / b << endl; break; 
            default: cout << "Invalid operator!" << endl;
        }

    }


// good luck:)
    return 0;
}

