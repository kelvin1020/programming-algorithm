#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

//函数声明
int countData(char data[], int alphabet[]);
int up2low(char data[]); //大写到小写

// 字符串中次数第2多的字母

int main()
{
	char data[501];
    int alphabet[26] = {0};
	cin.getline(data, 501);

    up2low(data);

    for (int i = 0; data[i] != '\0'; ++i)
    {
        if(data[i] >= 97 && data[i] <= 122) 
        {
            alphabet[data[i] - 97]++; 
        }
    }

    countData(data, alphabet);

// good luck:)
    return 0;
}

int countData(char data[], int alphabet[])
{
    int temp = 0;
    char *p = data + strlen(data) - 1; //指向末尾

    for (int i = 0; i < 26; ++i)
    {
        if (temp < alphabet[i])
        {
            temp = alphabet[i];
        }
    }

    //最大清0
    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] == temp)
        {
            alphabet[i] = 0;
        }
    }    

    //求次大
    temp = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (temp < alphabet[i])
        {
            temp = alphabet[i];
        }
    }

    //保存次大字母，非次大清0
    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] != temp)
        {
            alphabet[i] = 0;
        }
    }

    for(int i = 0; i < 26; ++i)
    {   
        if(alphabet[i] != 0)
        {
            if (p > strchr( data, (char) (97 + i) ) )
            {
                p = strchr( data, (char) (97 + i) );
            }
        }
    }

    cout << (char) (data[p - data] - 32) << "+" << data[p - data] << ":" << temp << endl;
    return 0;
}

int up2low(char data[])
{
    for (int i = 0; data[i] != '\0'; ++i)
    {
        if ( data[i] >= 65 && data[i] <= 90)
        {
            data[i] += 32; 
        }
    }
    return 0;
}