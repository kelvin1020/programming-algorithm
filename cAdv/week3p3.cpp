#include<iostream>
#include <cstring>
using namespace std;

//函数声明
int str2bool(char strseq[], int seq[], int size);
int evolve(int seq[], int index);
int evolver(int seq[], int index);


// 排队游戏
int main()
{
	char strseq[101] = {'\0'};
	int seq[100] = {0};
	int size;

	cin.getline(strseq, 101);

	size = strlen(strseq);

    str2bool(strseq, seq, size);

    for (int i = 0; i < size; ++i)
    {
    	if (seq[i] == -1)
    	{
    		// cout << evolve(seq, i) << ' ' << i << endl;
    		cout << evolver(seq, i) << ' ' << i << endl;    		
    	}
    }

// good luck:)
    return 0;
}

int str2bool(char strseq[], int seq[], int size)
{
	char a;
	a = strseq[0];

	for (int i = 0; i < size; ++i)
	{
		if (strseq[i] == a)
		{
			seq[i] = 1;			
		}
		else
		{
			seq[i] = -1;
		}

	}
	return 0;
}


// 返回某右括号的左括号
int evolve(int seq[], int index)
{
	int count = 0;

	for (int i = index; i >= 0; --i)
	{		
		count += seq[i];

		if (count == 0)
		{
			return i;
			break;
		}
	}
}



// 返回某右括号的左括号 - 递归方法
int evolver(int seq[], int index)
{
	while(seq[index - 1] == -1)
	{
		index = evolver(seq, index - 1);		
	}
	return index - 1;
}


