#include<iostream>

using namespace std;

main()
{
	
	int   a = 1;
	short b = 2;
	long  c = 3;
	char  d[2] = {'a', 'b'}; // 在及其吝啬内存的时候，对于特别小的数字，或可以用字符型数据存储？
				 // 但要进行类型转换

	int *e = NULL;
	short *f;	
	long *g;
	char *h;

	e = &a;
	f = &b;
	g = &c;	
	h = d;

	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;	
	cout << sizeof(c) << endl;
	cout << sizeof(d) << endl;

	cout << sizeof(e) << ' ' << e << endl;
	cout << sizeof(f) << ' ' << f << endl;	
	cout << sizeof(g) << ' ' << g << endl;

	cout << sizeof(h) << ' ' << *h << endl;
	cout << sizeof(h) << ' ' << *(h+1) << endl;	
	cout << endl;
	return 0;
}