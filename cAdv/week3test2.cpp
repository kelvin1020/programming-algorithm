
#include<iostream>
using namespace std;

//函数声明
double notation();

//逆波兰表达式

int main()
{
    cout << notation() << endl;
// good luck:)
    return 0;
}


double notation()
{
	char str[10];
	cin >> str;
	switch( str[0])
	{
		case '+':return notation() + notation();
		case '-':return notation() - notation();		
		case '*':return notation() * notation();
		case '/':return notation() / notation();
		default: return atof(str);
	}
}