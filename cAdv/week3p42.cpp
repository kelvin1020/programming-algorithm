#include<iostream>
using namespace std;

int main() {
	char a[101]= {'\0'} ,c[101] = {'\0'};
	while(cin.getline(a, 101))
	{
		cout << a << endl;
		
		for (int i = 0; a[i]!='\0'; i++) 
		{
			c[i] = a[i];
		}

	
		for (int j = 0, l; a[j] != '\0'; j++) 
		{
			if (a[j] == ')') 
			{
				for (l = j; l >= 0; l--) 
				{
					if (a[l] == '(') 
					{
						a[l] = 'p';
						a[j] = 'p';
						break;
					}
				}
			}
		}


		for (int i = 0; i<101; i++) 
		{
			if (a[i] == '(') 
			{
				c[i] = '$';
			} 

			else if (a[i] == ')') 
			{
				c[i] = '?';
			}
			
			else if (a[i] == '\0') 
			{
				break;
			}

			else 
			{
				c[i] = ' ';
			}
			
		}
		
		cout << c <<endl;
	}
	return 0;
}

