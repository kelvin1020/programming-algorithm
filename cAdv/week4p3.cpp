#include<iostream>
#include <cstring>
using namespace std;

//函数声明
char *outSentence(char word[]); //输入单词, 输出句子
int clearSen(char sen[]); //清空句子
int outSen(char sen[]); //输出句子

// 文字排版
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
        sentence = outSentence(word);
	}

    //最后一行输出
    if ( strlen(sentence) != 0) 
    {
        outSen(sentence);
    }

// good luck:)
    return 0;
}

char *outSentence(char word[]) //已有句子， 输入单词，输出现有句子
{
    static char sentence[81]={'\0'}; //局部静态变量，为避免使用全局变量引入
    static char *ps = sentence;      //局部静态变量

    if (strlen(sentence) + strlen(word) + 1 < 80) //不满80不输出
    {
        strcat(sentence, word);
        ps += strlen(word);
        *ps++ = ' ';                              //单词后空格   
    }
    else if ( strlen(word) == 80 - strlen(sentence) ) //刚好满80，输入单词，输出，复位
    {
        strcat(sentence, word);
        ps += strlen(word);
                                                  //无单词后空格
        outSen(sentence);                 //输出
        
        clearSen(sentence);                       //复位
        ps = sentence;  
    }
    else                                          //满80输出，不输入单词，输出，复位，输入单词
    {
        outSen(sentence);                 //输出

        clearSen(sentence);                       //复位
        ps = sentence;   

        strcat(sentence, word);                   //输入单词
        ps += strlen(word);
        *ps++ = ' ';                              //单词后空格   
    }
    return sentence;                              //返回句子
}

int clearSen(char sen[])
{
    for (char *p = sen; *p != '\0'; ++p)
    {
        *p = '\0';
    }
    return 0;
}

int outSen(char sen[])//不输出'/0' 及 ' '
{
    for (char *p = sen; p < sen + strlen(sen) ; ++p)
    {
        if(p == sen + strlen(sen) - 1 && *p == ' ') 
        {
            continue; //如果最后一个为空格，则跳过输出
        }  
        cout << *p;
    }

    cout << endl;
    // cout << strlen(sen) << endl;
    return 0;
}