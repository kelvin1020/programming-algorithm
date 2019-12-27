#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码

class Array2
{
private:
    int m, n; //m size, n size
    int **p;

public:
    Array2()
    {
        m = 0;
        n = 0;
        p = NULL;
    }

    Array2(int a, int b)
    {
        m = a;
        n = b;
        if (m == 0 || n == 0)
        {
            p = NULL;
        }
        else
        {
            p = new int*[m];
            for (int i = 0; i < m; i++)
            {
                p[i] = new int[n];
            }
        }
    }

    ~Array2()
    {
        if (p)
        {
            for (int i = 0; i < m; i++)
            {
                delete [] p[i];
            }
            delete p;
        } 
    }

    Array2 & operator=(const Array2 & a)
    {
        if( p == a.p)   //a = a
        {
            return *this;
        }

        if (a.p == NULL)  // a ==NULL
        {
            if (p)
            {
                for (int i = 0; i < m; i++)
                {
                    delete [] p[i];
                }
                delete p;
            } 
            p = NULL;
            m = 0;
            n = 0;

            return *this;
        }

        if (p)                    //p = a
        {
            for (int i = 0; i < m; i++)
            {
                delete [] p[i];
            }
            delete p;
        } 

        p = new int*[a.m];
        for (int i = 0; i < a.m; i++)
        {
            p[i] = new int[a.n];
        }

        memcpy(p, a.p, sizeof(int) * a.m * a.n);
        m = a.m;
        n = a.n;
        return *this;        
    }

    int * operator[](int a)
    {
        return p[a];
    }

    int operator()(int a, int b)
    {
        return p[a][b];
    }

};




int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}