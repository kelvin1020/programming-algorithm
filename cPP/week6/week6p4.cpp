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

    int t;                     // real time

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
    int addWarrior(int code, int num, int wstrength); // 0 dragon 、1 ninja、2 iceman、3 lion、4 wolf
    bool createWarrior(const int * createOrder);
    ~headquarter();
};


class warrior
{
private:
    int wnum;             //编号
    int wstrength;        //生命值
    int watk;             //攻击力

protected:
    const headquarter * wbase;  //从属基地
 
public:
    const char * weaponName[3] = {"sword", "bomb", "arrow"};
    warrior(int num, int strength, const headquarter *base):wnum(num), wstrength(strength), wbase(base){};  //{ cout<< wstrength << ' ' << wnum;};
    virtual int say()
    {
        return 0;
    };
    //~warrior();        //生命值降为0后析构
};


class dragon:public warrior
{
private:
   int weapon;
   double morale;

public:
    dragon(int num, int strength, const headquarter *base):warrior(num, strength, base)
    {
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
    ninja(int num, int strength, const headquarter *base):warrior(num, strength, base)
    {
        num += 1;
        weapons[0] = num%3;
        weapons[1] = (num+1)%3;        
    }
    virtual int say()
    {
        cout << "It has a " << weaponName[weapons[0]] << " and a " << weaponName[weapons[1]] << endl;
        return 0;
    }
};


class iceman:public warrior
{
private:
   int weapon;

public:
    iceman(int num, int strength, const headquarter *base):warrior(num, strength, base)
    {
        num += 1;
        weapon = num%3;
    }
    virtual int say()
    {
        cout << "It has a " << weaponName[weapon] << endl;
        return 0;
    }    
};

class lion:public warrior
{
private:
   int loyalty;

public:
    lion(int num, int strength, const headquarter *base):warrior(num, strength, base){};
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
    wolf(int num, int strength, const headquarter *base):warrior(num, strength, base){};
};

headquarter::headquarter(string name_, int m_, int nCity_, int r_, int k_, int tLimit_, const int *strengthList_, const int *atkList_)
{
    name = name_;
    t  = 0;   
    m = m_;
    num = 0; 
    numCir = 0;
    OutputFinished = false;
    for (int i = 0; i < 5; i++)
    {
        strengthList[i] = strengthList_[i];
    }
}


 int headquarter::addWarrior(int code, int num, int wstrength) // 0 dragon 、1 ninja、2 iceman、3 lion、4 wolf
{

    switch (code)
    {
    case 0: warriorList[num] = new dragon(num, wstrength, this); break;
    case 1: warriorList[num] = new ninja(num, wstrength, this); break;
    case 2: warriorList[num] = new iceman(num, wstrength, this); break;
    case 3: warriorList[num] = new lion(num, wstrength, this); break;
    case 4: warriorList[num] = new wolf(num, wstrength, this); break;        
    }
    return 0;
}

bool headquarter::createWarrior(const int * createOrder)
{
    int count = 0;
    int wstrength;
    const char* wname;

    for (; count < 5; numCir++)
    {
        numCir %= 5;
        wstrength = strengthList[createOrder[numCir]];
        wname = warriorNameList[createOrder[numCir]];

        if (m - wstrength >= 0)  //判断是否还能创建
        {
            addWarrior(createOrder[numCir],  num, wstrength);          // add Warrior
            m -= strengthList[createOrder[numCir]];                    //m decrease

            cout << setfill('0') << setw(3) << t++ << ":00 " << name << ' ' << wname << ' ' << ++num << " born"<< endl;
            ++warriorNum[createOrder[numCir]];  //next warrior
            warriorList[num-1]->say();   //say

            numCir++;
            return true;
        }
        count++;

    }

    if(OutputFinished == false)  // 如果不能创建，则
    {
        cout << setfill('0') << setw(3) << t << ' ' << name << ' ' << "headquarter stops making warriors" << endl;
        OutputFinished = true;
    }
    return false;         
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
    bool a,b;
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

        for (int i = 0;; i++)
        {
           a = !red.createWarrior(redOrder);
           b = !blue.createWarrior(blueOrder);
           
           if (a && b)
           {
               break;
           }
        }
    }
    return 0;
}

