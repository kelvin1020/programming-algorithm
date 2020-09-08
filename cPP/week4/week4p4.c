#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;
// 大整数的加减乘除

void reverse_string(string &ans)
{
	int n = ans.length(), i;
	char tmp;
	for (i=0; i<n/2; i++)
	{
		tmp = ans.at(i);
		ans.at(i) = ans.at(n-i-1);
		ans.at(n-i-1) = tmp;
	}
}
 
void remove_zeros(string &ans)
{
	if (ans == "0")
	{
		return;
	}
	int i = 0;
	for (i=0; i<ans.length(); i++)
	{
		if (ans.at(i) != '0')
		{
			break;
		}
	}
	ans = ans.substr(i);
}
 
class BigInt {
public:
	string num;	// unsigned number
 
	BigInt(void) {}
	BigInt(string Num): num(Num) {}
 
	BigInt Add(const BigInt & b)
	{
		string ans;
		int i, n1 = min(num.length(), b.num.length()), n2 = max(num.length(), b.num.length()), a1, a2, s = 0, si = 0;
		for (i=0; i<n1; i++)
		{
			a1 = num.at(num.length()-i-1) - '0';
			a2 = b.num.at(b.num.length()-i-1) - '0';
			if (a1 + a2 + si< 10)
			{
				s = a1 + a2 + si;
				si = 0;
			}
			else
			{
				s = (a1 + a2 + si) - 10;
				si = 1;
			}
			ans.push_back((char)(s + '0'));
		}
		for (i=n1; i<n2; i++)
		{
			if (n2 == num.length())
			{
				a1 = num.at(n2-i-1) - '0';
			}
			else
			{
				a1 = b.num.at(n2-i-1) - '0';
			}
			if (a1 + si < 10)
			{
				s = a1 + si;
				si = 0;
			}
			else
			{
				s = (a1 + si) - 10;
				si = 1;
			}
			ans.push_back((char)(s + '0'));
		}
		if (si == 1)
		{
			ans.push_back('1');
		}
		reverse_string(ans);
		return BigInt(ans);
	}
 
	int Compare(const BigInt & b)	// -1: <   0: ==   1: >
	{
		int n1 = num.length(), n2 = b.num.length(), i = 0;
		if (n1 > n2)
		{
			return 1;
		}
		else if (n1 < n2)
		{
			return -1;
		}
		else
		{
			for (i=0; i<n1; i++)
			{
				if (num.at(i) > b.num.at(i))
				{
					return 1;
				}
				else if (num.at(i) < b.num.at(i))
				{
					return -1;
				}
			}
			return 0;
		}
	}
 
	BigInt Subtract(const BigInt & b)
	{
		string ans;
		int oper = Compare(b), i, n1 = num.length(), n2 = b.num.length(), a1, a2, s = 0, si = 0;
		if (oper == 0)
		{
			return BigInt("0");
		}
		else if (oper == -1)
		{
			n1 = b.num.length();
			n2 = num.length();
			for (i=0; i<n2; i++)
			{
				a1 = b.num.at(n1-i-1) - '0';
				a2 = num.at(n2-i-1) - '0';
				if (a1 - a2 - si >= 0)
				{
					s = a1 - a2 - si;
					si = 0;
				}
				else
				{
					s = (a1 - a2 - si) + 10;
					si = 1;
				}
				ans.push_back((char)(s + '0'));
			}
			for (i=n2; i<n1; i++)
			{
				a1 = b.num.at(n1-i-1) - '0';
				if (a1 - si >= 0)
				{
					s = a1 - si;
					si = 0;
				}
				else
				{
					s = (a1 - si) + 10;
					si = 1;
				}
				ans.push_back((char)(s + '0'));
			}
			reverse_string(ans);
			remove_zeros(ans);
			string ans1 = "-";
			ans = ans1.append(ans);
		}
		else
		{
			for (i=0; i<n2; i++)
			{
				a1 = num.at(n1-i-1) - '0';
				a2 = b.num.at(n2-i-1) - '0';
				if (a1 - a2 - si >= 0)
				{
					s = a1 - a2 - si;
					si = 0;
				}
				else
				{
					s = (a1 - a2 - si) + 10;
					si = 1;
				}
				ans.push_back((char)(s + '0'));
			}
			for (i=n2; i<n1; i++)
			{
				a1 = num.at(n1-i-1) - '0';
				if (a1 - si >= 0)
				{
					s = a1 - si;
					si = 0;
				}
				else
				{
					s = (a1 - si) + 10;
					si = 1;
				}
				ans.push_back((char)(s + '0'));
			}
			reverse_string(ans);
			remove_zeros(ans);
		}
		return BigInt(ans);
	}
 
	BigInt Multiply(const BigInt & b)
	{
		BigInt ans("0");
		string tmp;
		int i, j, k, n1 = num.length(), n2 = b.num.length(), a1, a2, s = 0, si = 0;
		for (j=n2-1; j>=0; j--)
		{
			a2 = b.num.at(j) - '0';
			if (a2 == 0)
			{
				continue;
			}
			tmp.clear();
			s = 0;
			si = 0;
			for (k=0; k<n2-1-j; k++)
			{
				tmp.push_back('0');
			}
			for (i=n1-1; i>=0; i--)
			{
				a1 = num.at(i) - '0';
				s = (a1 * a2 + si) % 10;
				si = (a1 * a2 + si) / 10;
				tmp.push_back((char)(s + '0'));
			}
			if (si != 0)
			{
				tmp.push_back((char) (si + '0'));
			}
			reverse_string(tmp);
			ans = ans.Add(BigInt(tmp));
		}
		return ans;
	}
 
	BigInt Divide(const BigInt & b)
	{
		string ans;
		BigInt div;
		int n1 = num.length(), n2 = b.num.length(), i, tmp = 0;
		if (n1 < n2)
		{
			return BigInt("0");
		}
		div.num = num.substr(0, n2-1);
		for (i = 0; i <= n1 - n2; i++)
		{
			div.num.push_back(num.at(i+n2-1));
			tmp = 0;
			while (div.Compare(b) >= 0)
			{
				tmp++;
				div = div.Subtract(b);
			}
			ans.push_back((char) (tmp + '0'));
		}
		remove_zeros(ans);
		return BigInt(ans);
	}
};

string operator+(BigInt a, BigInt b)
{
    return a.Add(b).num;
}

string operator-(BigInt a, BigInt b)
{
    return a.Subtract(b).num;
}

string operator*(BigInt a, BigInt b)
{
    return a.Multiply(b).num;
}

string operator/(BigInt a, BigInt b)
{
    return a.Divide(b).num;
}



int main()
{
	BigInt a,b;
	char o;
	cin >> a.num >> o >> b.num;

	switch (o)
	{
	case '+':
		cout << a + b;
		break;
	case '-':
		cout << a - b;
		break;
	case '*':
		cout << a * b;
		break;
	case '/':
		cout << a / b;
		break;
	default: break;
	}
	return 0;

}