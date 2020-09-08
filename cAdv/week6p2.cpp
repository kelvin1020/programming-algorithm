#include<iostream>
#include<iomanip>
using namespace std;

//函数声明
char *MapData(char data[]);
int clearSen(char sen[]);

// 配对碱基链条
int main()
{
	int n;
	char data[1000][256] = {'\0'};
	cin >> n;
    cin.get();

	for (int i = 0; i < n; i++)
	{
		cin.getline(data[i], 255 + 1);
	}


	for (int i = 0; i < n; i++)
	{
		cout << MapData(data[i]) << endl;
	}

// good luck:)
    return 0;
}

char *MapData(char datai[])
{
    static char match[256] = {'\0'};
    clearSen(match);

    for (int i = 0;  datai[i] != '\0'; ++i)
    {
        switch(datai[i])
        {
            case 'A': match[i] = 'T'; break;            
            case 'T': match[i] = 'A'; break;  
            case 'C': match[i] = 'G'; break;              
            case 'G': match[i] = 'C'; break;  
        }
    }
    return match;
}

int clearSen(char sen[])
{
    for (char *p = sen; *p != '\0'; ++p)
    {
        *p = '\0';
    }
    return 0;
}