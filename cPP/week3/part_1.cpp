#include <iostream>
using namespace std;
class A {
public:
    int val;
// 在此处补充你的代码
    A()
    {
        val = 0;
    }
    
    int& GetObj()
    {
        int &p = val;
        return p;
    }
};
main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}