
#include<iostream>
#include <iomanip>
using namespace std;

//函数声明
int inputData(float data[][4]);
int outputData(float data[][4]);

// 发票统计
int main()
{

    float data[4][4] = {0};

    //输入数据
    inputData(data);

    //输出数据
    outputData(data);

// good luck:)
    return 0;
}


int inputData(float data[][4])
{
   int id, n;
   char kind;
   float temp;

   for (int k = 0; k < 3; ++k)
   {
       cin >> id >> n;
       for (int i = 0; i < n; ++i)
       {
           cin >> kind >> temp;
           switch (kind)
           {
                case 'A': data[id][1] += temp; break;
                case 'B': data[id][2] += temp; break;
                case 'C': data[id][3] += temp; break;
           }
       }
   }
    return 0;
}

int outputData(float data[][4])
{
    char kind[] = {'\0', 'A', 'B', 'C'};

    for (int i = 1; i < 4; ++i)
    {
        cout << i << ' ' << fixed << setprecision(2) << data[i][1] + data[i][2] + data[i][3] << endl;
    }


    for (int j = 1; j < 4; ++j)
    {
        cout << kind[j] << ' ' << fixed << setprecision(2) << data[1][j] + data[2][j] + data[3][j] << endl;
    }


    cout << endl;

    return 0;
}
