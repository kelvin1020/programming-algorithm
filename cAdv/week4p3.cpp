#include<iostream>
#include <cstring>
using namespace std;

//函数声明
char *outSentence(char word[]); //已有句子， 输入单词
int clearSen(char sen[]); //清空句子

// 括号匹配问题
int main()
{           
	char word[41]={'\0'};
	char *sentence = NULL; 
    int n;
    cin >> n;
    cin.get(); //读取换行符

	for(int i = 0; i < n; ++i)
	{
        cin >> word;
        if (strlen(sentence = outSentence(word)) == 0)
        {
            sentence = outSentence(word);
        }
   
	}

    //最后输出
    if ( strlen(sentence) != 0) 
    {
        cout << sentence << endl;
    }

// good luck:)
    return 0;
}

char *outSentence(char word[]) //已有句子， 输入单词，输出现有句子
{
    static char sentence[81]={'\0'}; //局部静态变量，为避免使用全局变量引入
    static char *ps = sentence;      //局部静态变量
    char *pw = NULL;

    if (strlen(sentence) + strlen(word) + 1 < 80) //不满80不输出
    {
        for(pw = word; *pw != '\0'; pw++, ps++)
        {
            *ps = *pw; //word
        }
        *ps++ = ' '; //blank     
    }
    else if ( strlen(word) == 80 - strlen(sentence) ) //单词输入
    {
        for(pw = word; *pw != '\0'; pw++, ps++)
        {
            *ps = *pw; //word, no blank
        }
        cout << sentence << endl; 
        // cout << sentence << strlen(sentence) << endl; 
        clearSen(sentence);
        ps = sentence;  
        *ps = ' ';     //标记位，指针不移动, 为下文判断用
    }
    else //不满80输出
    {
        *(--ps) = '\0';
        cout << sentence << endl;
        // cout << sentence << strlen(sentence) << endl; 
        clearSen(sentence);
        ps = sentence;       
    }
    return sentence;
}

int clearSen(char sen[])
{
    for (char *p = sen; *p != '\0'; ++p)
    {
        *p = '\0';
    }
    return 0;
}



