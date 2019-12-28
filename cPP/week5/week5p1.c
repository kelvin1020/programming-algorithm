// 在此处补充你的代码
class MyString: public string
{

public:
    MyString():string() {};                     //参数为空
    MyString(const char* str):string(str) {};   //参数为字符串
    MyString(const MyString & a):string(a) {};  //复制构造函数
    MyString(string str):string(str) {};        //类型转换构造函数
    MyString operator()(int a, int b)
    {
        return substr(a,b);
    }

};