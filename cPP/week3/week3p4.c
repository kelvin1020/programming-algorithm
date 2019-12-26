#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//魔兽世界之一： 备战

class warrior
{
private:          
    int kind;                  // 0 dragon 、1 ninja、2 iceman、3 lion、4 wolf
      
public:
    string wname;
    string wnameList[5] = {"dragon ",  "ninja ", "iceman ", "lion ", "wolf "};
    int strength;
    int atk = 0;
    int wnum;  

    int setWarrior(int kind_, const int * strengthList)
    {
        kind = kind_;
        wname = wnameList[kind];
        strength = strengthList[kind];
        wnum = 0;
        return 0;
    }

    int addWarrior()
    {
        wnum++;
        return 0;
    }
};

class headquater 
{
private:
    string name;  
    int t;                     // time
    int m;                     // total strength
    int num;                   // warrior number 
    int numCir;                 // created warrior number   
    int strengthList[5];       // dragon 、ninja、iceman、lion、wolf 
    bool OutputFinished;               
    warrior warriorList[5];    // dragon 、ninja、iceman、lion、wolf 

public:
    headquater(string name_, int m_, const int * strengthList_)
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

        for (int i = 0; i < 5; i++)
        {
            warriorList[i].setWarrior(i, strengthList);
        }
    }

    bool createWarriorT(const int * createOrder)
    {
        int count = 0;
        for (; count < 5; numCir++)
        {
            numCirAdd(numCir);
            if (m - warriorList[createOrder[numCir]].strength >= 0)
            {
                warriorList[createOrder[numCir]].addWarrior();  // add Warrior
                m -= warriorList[createOrder[numCir]].strength; //m decrease
                cout << setfill('0') << setw(3) << t++ << ' ' << name << warriorList[createOrder[numCir]].wname \
                << ++num << " born with strength " << warriorList[createOrder[numCir]].strength << ','\
                << warriorList[createOrder[numCir]].wnum << ' ' << warriorList[createOrder[numCir]].wname \
                << "in " << name << "headquater" << endl;
                numCir++;
                return true;
            }
            count++;
        }

        if(OutputFinished == false)
        {
            cout << setfill('0') << setw(3) << t << ' ' << name << "headquarter stops making warriors" << endl;
            OutputFinished = true;
        }
        return false;                
    }

    int numCirAdd(int & number)
    {
        if(number > 4)
        {
            number -= 5;
        }
        return 0;
    }
};

int main()  
{
    int n;                  // case number
    int m;                  // total life value in headquater
    int strengthList[5];    // dragon 、ninja、iceman、lion、wolf 
    int redOrder[5] = {2, 3, 4, 1, 0};
    int blueOrder[5] = {3, 0, 1, 2, 4};
    bool a,b;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;

        for (int i = 0; i < 5; i++)
        {
            cin >> strengthList[i];
        }

        headquater red("red ", m, strengthList), blue("blue ", m, strengthList);

        cout << "Case:" << i + 1 << endl;

        for (int i = 0;; i++)
        {
           a = !red.createWarriorT(redOrder);
           b = !blue.createWarriorT(blueOrder);
           
           if (a && b)
           {
               break;
           }
        }
    }
    return 0;
}