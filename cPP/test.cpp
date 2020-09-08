#include <iostream>
using namespace std;

int i = 0;


class A
{
public:
    A()
    {
        cout << "Constructed" << endl;
    }

    ~A()
    {
        cout << "i = " << i++ << " "<< "Destructed" << endl;
    }
};


int main()
{
    A *p = new A[2];
    A *p2 = new A;
    A a;

    delete p2;
    delete [] p;
}