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
    int strengthList[5];       // dragon 、ninja、iceman、lion、wolf 
    warrior warriorList[5];    // dragon 、ninja、iceman、lion、wolf 

public:
    headquater(string name_, int m_, const int * strengthList_)
    {
        name = name_;
        m = m_;
        num = 0; 
        t  = 0;   

        for (int i = 0; i < 5; i++)
        {
            strengthList[i] = strengthList_[i];
        }

        for (int i = 0; i < 5; i++)
        {
            warriorList[i].setWarrior(i, strengthList);
        }
    }

    int createWarrior(const int * createOrder)
    {
        bool flag[5] = {false, false, false, false, false};
        while (m > 0)
        {
            for (int i = 0; i < 5; i++)
            {
                if (m - warriorList[createOrder[i]].strength > 0)
                {
                    warriorList[createOrder[i]].addWarrior();  // add Warrior
                    m -= warriorList[createOrder[i]].strength; //m decrease
                    

                    cout << setfill('0') << setw(3) << t++ << ' ' << name << warriorList[createOrder[i]].wname \
                    << ++num << " born with strength " << warriorList[createOrder[i]].strength << ','\
                    << warriorList[createOrder[i]].wnum << ' ' << warriorList[createOrder[i]].wname \
                    << "in " << name << "headquater" << endl;
                }
                else
                {
                    flag[i] = true;
                }
            }

            if (flag[0] && flag[1] && flag[2] && flag[3] && flag[4] ) //stop create
            {
                cout << setfill('0') << setw(3) << t << ' ' << name << "headquarter stops making warriors" << endl;
                break;
            }

            for (int i = 0; i < 5; i++)
            {
                flag[i] = false;
            }
            
        }
    }


    int outputM()
    {
        cout << m << endl;
        return 0;
    }

    int outputSL()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << strengthList[i] << ' ';
        } 
        cout << endl;
    }



};


int main()  
{
    int n;                  // case number
    int m;                  // total life value in headquater
    int strengthList[5];    // dragon 、ninja、iceman、lion、wolf 
    int redOrder[5] = {2, 3, 4, 1, 0};
    int blueOrder[5] = {3, 0, 1, 2, 4};
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

        red.createWarrior(redOrder);
        blue.createWarrior(blueOrder);

        // blue.outputSL();
        // blue.outputM();
    

    }
    return 0;
}