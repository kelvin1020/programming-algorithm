#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//魔兽世界终极版

// 0 dragon 、1 ninja、2 iceman、3 lion、4 wolf


class warrior;

class headquarter
{
private:
    string name;

    int m;                     // total strength of headquarter( 1 <= m <= 10000)
    int nCity;                 // city number    ( 1 <= N <= 20 )
    int r;                     // atk of arrow
    int k;                     // loyalty decrease per round of lion
    int tLimit;                // output events of 0 <= T <= 5000

    int num;                   // warrior number 
    int numCir;                 // created warrior number   
    bool OutputFinished; 

    int warriorNum[5] = {0};
    const char* warriorNameList[5] = {"dragon", "ninja", "iceman", "lion", "wolf"}; 
    warrior *warriorList[10000] = {NULL};    // dragon 、ninja、iceman、lion、wolf 

    friend class dragon;
    friend class lion;    

public:

    int strengthList[5];       // dragon 、ninja、iceman、lion、wolf
    int atkList[5];       //the atk of  dragon 、ninja、iceman、lion、wolf

    headquarter(string name_, int m_, int nCity_, int r_, int k_, int tLimit_, const int *strengthList_, const int *atkList_);
    int addWarrior(int code, int num, int wstrength, int watk); // 0 dragon 、1 ninja、2 iceman、3 lion、4 wolf
    bool createWarrior(const int * createOrder, int t_); // t:00
    bool lionRunAway(int t_); // t:05

    ~headquarter();
};


class warrior
{
private:
    int wnum;             //编号
    int wstrength;        //生命值
    int watk;             //攻击力
    friend class headquarter;

protected:
    const headquarter * wbase;  //从属基地
 
public:
    string wname = "None";         //类型
    const char * weaponName[3] = {"sword", "bomb", "arrow"};
    warrior(int num, int strength, int atk, const headquarter *base):wnum(num), wstrength(strength), watk(atk), wbase(base){};  //{ cout<< wstrength << ' ' << wnum;};
    virtual int say()
    {
        return 0;
    };
    virtual ~warrior(){};   //析构，生命值降为0后？
};


class dragon:public warrior
{
private:
   int weapon;
   double morale;

public:
    dragon(int num, int strength, int atk, const headquarter *base):warrior(num, strength, atk, base)
    {
        wname = "dragon";
        num += 1;
        weapon = num%3;

    }
    virtual int say()
    {
        morale = ((double) (wbase->m)) / ((double) (wbase->strengthList[0]));
        cout <<  "Its morale is " << setiosflags(ios::fixed) << setprecision(2)\
        << morale << endl;
        return 0;
    }
};

class ninja:public warrior
{
private:
   int weapons[2];

public:
    ninja(int num, int strength, int atk, const headquarter *base):warrior(num, strength, atk, base)
    {
        wname = "ninjia";
        num += 1;
        weapons[0] = num%3;
        weapons[1] = (num+1)%3;        
    }
    // virtual int say()
    // {
    //     cout << "It has a " << weaponName[weapons[0]] << " and a " << weaponName[weapons[1]] << endl;
    //     return 0;
    // }
};


class iceman:public warrior
{
private:
   int weapon;

public:
    iceman(int num, int strength, int atk, const headquarter *base):warrior(num, strength, atk, base)
    {
        wname = "iceman";
        num += 1;
        weapon = num%3;
    }
    // virtual int say()
    // {
    //     cout << "It has a " << weaponName[weapon] << endl;
    //     return 0;
    // }    
};

class lion:public warrior
{
private:
   int loyalty;

public:
    lion(int num, int strength, int atk, const headquarter *base):warrior(num, strength, atk, base)
    {
        wname = "lion";
    }
    bool ifRun()
    {
        if (loyalty <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    virtual int say()
    {
        loyalty = (wbase->m);
        cout << "It's loyalty is " << loyalty << endl;
        return 0;
    }       
};

class wolf:public warrior
{
public:
    wolf(int num, int strength, int atk, const headquarter *base):warrior(num, strength, atk, base)
    {
        wname = "wolf";
    }
};

headquarter::headquarter(string name_, int m_, int nCity_, int r_, int k_, int tLimit_, const int *strengthList_, const int *atkList_)
{
    name = name_;
    m = m_;
    num = 0; 
    numCir = 0;
    OutputFinished = false;
    for (int i = 0; i < 5; i++)
    {
        strengthList[i] = strengthList_[i];
    }
    for (int i = 0; i < 5; i++)
    {
        atkList[i] = atkList_[i];
    }
}


 int headquarter::addWarrior(int code, int num, int wstrength, int watk) // 0 dragon 、1 ninja、2 iceman、3 lion、4 wolf
{

    switch (code)
    {
    case 0: warriorList[num] = new dragon(num, wstrength, watk, this); break;
    case 1: warriorList[num] = new ninja(num, wstrength, watk, this); break;
    case 2: warriorList[num] = new iceman(num, wstrength, watk, this); break;
    case 3: warriorList[num] = new lion(num, wstrength, watk, this); break;
    case 4: warriorList[num] = new wolf(num, wstrength, watk, this); break;        
    }
    return 0;
}

bool headquarter::createWarrior(const int * createOrder, int t_) // t:00
{
    int count = 0;
    int wstrength;
    int watk;
    const char* wname;

    for (; count < 5; numCir++)
    {
        numCir %= 5;
        wstrength = strengthList[createOrder[numCir]];
        watk = atkList[createOrder[numCir]];
        wname = warriorNameList[createOrder[numCir]];

        if (m - wstrength >= 0)  //判断是否还能创建
        {
            addWarrior(createOrder[numCir],  num, wstrength, watk);          // add Warrior
            m -= strengthList[createOrder[numCir]];                    //m decrease

            cout << setfill('0') << setw(3) << t_ << ":00 " << name << ' ' << wname << ' ' << ++num << " born"<< endl;
            ++warriorNum[createOrder[numCir]];  //next warrior
            warriorList[num-1]->say();   //say

            numCir++;
            return true;
        }
        count++;

    }

    if(OutputFinished == false)  // 如果不能创建，则
    {
        cout << setfill('0') << setw(3) << t_ << ' ' << name << ' ' << "headquarter stops making warriors" << endl;
        OutputFinished = true;
    }
    return false;         
}

bool headquarter::lionRunAway(int t_) // t:05
{
    lion *runLion = NULL;
    bool ifRun = false;

    for (int i = 0; warriorList[i] != NULL && warriorList[i]->wname != "dead"; i++)
    {
        if (warriorList[i]->wname == "lion")
        {
            runLion = (lion *) warriorList[i];  //强制类型转换，将基类指正转换为派生类，以调用派生类函数，特征
            if (runLion->ifRun() == true)
            {
                warriorList[i]->wname = "dead";
                cout << setfill('0') << setw(3) << t_ << ":05 " << name << ' ' << "lion" << ' ' << warriorList[i]->wnum
                     << " ran away" << endl;
            }
        }
        ifRun = true;
    }

    return ifRun;
}

headquarter::~headquarter()
{
    for (int i = 0; warriorList[i] != NULL; i++)
    {
        delete  warriorList[i];
        warriorList[i] = NULL;
    }
}

int main()  
{

    int n;                  // case number

    int m;                  // total strength of headquarter( 1 <= m <= 10000)
    int nCity;              // city number    ( 1 <= N <= 20 )
    int r;                  // atk of arrow
    int k;                  // loyalty decrease per round of lion
    int tLimit;             // output events of 0 <= T <= 5000

    int strengthList[5];    // dragon 、ninja、iceman、lion、wolf (0 ~ 10000)
    int atkList[5];         // the atk of dragon 、ninja、iceman、lion、wolf

    int redOrder[5] = {2, 3, 4, 1, 0};
    int blueOrder[5] = {3, 0, 1, 2, 4};
    // bool a,b;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m >> nCity >> r >> k >> tLimit;

        for (int i = 0; i < 5; i++)
        {
            cin >> strengthList[i];
        }

        for (int i = 0; i < 5; i++)
        {
            cin >> atkList[i];
        }

        headquarter red("red", m, nCity, r, k, tLimit, strengthList, atkList), blue("blue", m, nCity, r, k, tLimit, strengthList, atkList);

        cout << "Case:" << i + 1 << endl;

        ////////////////
        tLimit = 5;   //
        /////////////// 修改终止条件！


        for (int i = 0; i <= tLimit; i++) //i 整点时刻
        {
            red.createWarrior(redOrder, i);      //t:00
            blue.createWarrior(blueOrder, i);    //t:00

            red.lionRunAway(i);                //t:05
            blue.lionRunAway(i);               //t:05
        }
    }
    return 0;
}

