#include<iostream>
#include<iomanip>
using namespace std;

//函数声明
int sortMat(int num[], float amat[], int m);
int findMat(int num[], float amat[], int m, float a);

// 分配病房
int main()
{
	int m;
	float a;
	int num[50];
	float amat[50];

	cin >> m >> a;

	for (int i = 0; i < m; i++)
	{
		cin >> num[i] >> amat[i];
	}

	sortMat(num, amat, m);
	findMat(num, amat, m, a);

// good luck:)
    return 0;
}

int sortMat(int num[], float amat[], int m)
{
	int temp1 = 0;
	float temp2 = 0.;

	for (int i = 0; i < m-1; ++i)
	{
		for(int j = i; j < m; ++j)
		{
			if (amat[i] < amat[j])
			{
				temp1 = num[i];
				num[i] = num[j];
				num[j] = temp1;
				
				temp2 = amat[i];
				amat[i] = amat[j];
				amat[j] = temp2;
			}
		}
	}
	return 0;
}

int findMat(int num[], float amat[], int m, float a)
{
	bool flag = false;
	for(int i = 0; amat[i] > a; i++)
	{
		cout << setw(3) << setfill('0') << num[i] << " " << fixed << setprecision(1) << amat[i] << endl;
		flag = true;
	}

	if (flag == false)
	{
		cout << "None." << endl; 
	}

	return 0;
}

