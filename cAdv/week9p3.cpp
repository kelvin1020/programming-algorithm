#include<iostream>
using namespace std;

//函数声明
int judge(int a, int b, int c);

// 运算符判定

int main()
{

    char a_[5], b_[5], c_[5];
    int a, b, c;

    cin.getline(a_, 5, ',');
    cin.getline(b_, 5, ',');
    cin.getline(c_, 5);    

    a = atoi(a_);
    b = atoi(b_);
    c = atoi(c_);

    judge(a, b, c);

// good luck:)
    return 0;
}

int judge(int a, int b, int c)
{

    if(a + b == c)
    {
        cout << '+' << endl;
    }
    else if (a - b == c)
    {
        cout << '-' << endl;
    }
    else if (a * b == c)
    {
        cout << '*' << endl;
    }
    else if (a / b == c)
    {
        cout << '/' << endl;
    }
    else if (a % b == c)
    {
        cout << '%' << endl;
    }
    else
    {
        cout << "error" << endl;
    }
    return 0;
}