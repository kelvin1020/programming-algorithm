#include <iostream>
using namespace std;

class student
{
private:
    char name[50] = {'\0'};
    int age = 0;
    char number[50] = {'\0'};
    int grade[4] = {0};

public:
    int readData();
    int outputData();
};

int student::readData()
{
    cin.getline(name, 50, ',');
    cin >> age;
    cin.get();  //读取掉','
    cin.getline(number, 50, ',');

    for (int i = 0; i < 4; i++)
    {
        cin >> grade[i];
        cin.get();
    }
    return 0;
}

int student::outputData()
{
    int average = 0;
    average = (grade[0] +  grade[1] +  grade[2] +  grade[3]) / 4;
    cout << name << ',' << age << ',' << number << ',' << average << endl;
    return 0;
}

int main()
{
    student a;
    a.readData();
    a.outputData();
}