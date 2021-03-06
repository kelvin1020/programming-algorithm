#include<iostream>
#include <cstring>
using namespace std;

//函数声明
int str2blank(char strseq[], char seq[], int size);
int evolve(char seq[], int size);

// 括号匹配问题
int main()
{
	char strseq[101]={'\0'}, seq[101]= {'\0'};
	int size, key = 0;

	while(cin.getline(strseq, 101))
	{

		cout << strseq  << endl;

		size = strlen(strseq);
		str2blank(strseq, seq, size);

		evolve(seq, size);


		for (int j = size - 1; j >= 0; --j)
		{
	
			if (seq[j] == '?' || seq[j] == '$')
			{
				key = j + 1;
				break;
			} 
		}

	
		for (int i = 0; i < key; ++i)
		{
			cout << seq[i]; 
		}

		cout << endl;
	}

// good luck:)
    return 0;
}

int str2blank(char strseq[], char seq[], int size)
{

	for (int i = 0; i < size; ++i)
	{
		if (strseq[i] == '(' || strseq[i] == ')')
		{
			seq[i] = strseq[i];			
		}
		else
		{
			seq[i] = ' ';
		}

	}
	return 0;
}


// 括号匹配与否，否则标记， 未使用递归
int evolve(char seq[], int size) // flag == index + 1
{

	for (int i = 1; i < size - 1; ++i)  //distance
	{		
		for (int j = 0; (j < size - 1) && (j + i < size); ++j)
		{
			if (seq[j] == '(' && seq[j + i] == ')')
			{
				seq[j] = ' ';
				seq[i + j] = ' ';
			}
		}
	}

	for (int i = 0; i < size; ++i)
	{
		if (seq[i] == '(')
		{
			seq[i] = '$';
		}

		if (seq[i] == ')')
		{
			seq[i] = '?';
		}
	}

	return 0;
}
