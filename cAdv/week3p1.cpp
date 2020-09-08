#include<iostream>
#include <cstring>
using namespace std;

//函数声明
int getWord(char sentence[], char word[], int a, int b);
int rWord(char word[], int n, int size);

// 单词翻转
int main()
{
	bool flag = false;
	int size = 0;

	char sentence[501] = {'\0'}; 

	cin.getline(sentence, 501);

	for (int i = 0; i < strlen(sentence) + 1; ++i)
	{
		if (sentence[i] == ' ' || sentence[i] == '\0')
		{
			if (size > 0)
			{
				char wordtemp[501] = {'\0'}; 							
				getWord(sentence, wordtemp, i-1-size + 1, i-1);
				rWord(wordtemp, size, size);
			}

			flag = false;
			size = 0;

			if (sentence[i] != '\0')// 不输出\0
			{
				cout << sentence[i];
			}

		}

		else
		{
			flag = true;
			size++;
		}
	}

	cout << endl;
// good luck:)
    return 0;
}

int getWord(char sentence[], char word[], int a, int b)
{
	for (int i = a, j = 0; i < b + 1; ++i, ++j)
	{
		word[j] = sentence[i];
	}
	return 0;
}


int rWord(char word[], int n, int size)
{
	if (n == 1)
	{
		cout << word[size - 1];
	}

	else
	{
		rWord(word, n-1, size);
		cout << word[size - n];
	}
    return 0;
}