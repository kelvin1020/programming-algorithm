#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

//结构体
struct coord  //坐标
{
    int x, y;
};



//函数声明
int outputMat(char mat[][101], int n, int m);
coord getCoord(char mat[][101], int n, int m, char target); //返回目标点的坐标
bool isLegal(char mat[][101], int n, int m, coord start);   //移动是否合法
int calMat(char mat[][101], int n, int m, coord position);  //计算最短步数

bool *getPossibleDirection(char mat[][101], int n, int m, coord position, coord posList[]) ;//获取合法方向
bool isInPosList(coord position, coord posList[]);            //是否走过？

coord move(coord position, char order);


//    

static coord posList[300] ; 
static int   posk = 0;

// 走出迷宫

int main()
{
    int n, m;
    char mat[101][101] = {'\0'};

    cin >> n >> m;
    cin.get();

    for (int i = 0; i < n; i++)
    {
        cin.getline(mat[i], m + 1);
    }
    
    cout << endl;
    outputMat(mat,n, m);


    coord start = getCoord(mat, n, m, 'S');

    if (posk == 0)
    {
        posList[posk++] = start; 

        for (int i = 1; i < 300; i++)
        {
            posList[i].x = -1;
            posList[i].y = -1;
        }
    }

    cout << calMat(mat, n, m, start) << endl;

// good luck:)
    return 0;
}

int outputMat(char mat[][101], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}

int calMat(char mat[][101], int n, int m, coord position)
{
    static coord end = getCoord(mat, n, m, 'T');
    static char moveList[4] = {'u', 'd', 'l', 'r'}; //动作列表

    bool flag = false;
    coord temp = position;
    
    int returnValue = -3;
    int record[4] = {-1, -1, -1, -1};
    int minValue = 1000;
    bool *posDirection;

    if (position.x == end.x && position.y == end.y) //如果位置到达终点，返回步数0
    {
        return 0;
    }
    else
    {
     //如果没到达，则移动，并返回最小步数

        posDirection = getPossibleDirection(mat, n, m, position, posList);
        //得到可能的行动， 不能等于已经走过的

        for (int i = 0; i < 4; i++)
        {
            if (posDirection[i])
            {
                position = move(position, moveList[i]);
                posList[posk++] = position; 

                returnValue = calMat(mat, n, m, position); //如果不是死胡同-1，则返回值
                if (returnValue != -1)
                {
                    record[i] = returnValue;
                    flag = true;
                }
                
                posList[--posk] = {-1, -1};              //清除效果              
                position = temp;
                posDirection = getPossibleDirection(mat, n, m, position, posList);    //重新更新可选方向，避免被子调用覆盖                
            } 
        }
        
        //选择最小步数
        for (int i = 0; i < 4; ++i)
        {
            if (record[i] != -1)
            {
                if(minValue > record[i])
                {
                    minValue = record[i];
                }
            }
        }

        if (flag == false) //死胡同
        {
            return -1;
        }
        
        if (minValue != 1000) //返回值
        {
            return 1 + minValue;
        }
    }
}

coord getCoord(char mat[][101], int n, int m, char target)
{
    coord position = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == target)
            {
                position.x = i; 
                position.y = j;
                return position;
            }
        }
    }

    return position;
}


bool *getPossibleDirection(char mat[][101], int n, int m, coord position, coord posList[])
{
    static bool ans[4] = {false, false, false, false};
    coord u, d, l, r;

    for (int i = 0; i < 4; i++) // 清0
    {
        ans[i] = false;
    }

    u.x = position.x - 1; u.y = position.y;
    d.x = position.x + 1; d.y = position.y;
    l.x = position.x    ; l.y = position.y - 1;
    r.x = position.x    ; r.y = position.y + 1;

    if (isLegal(mat, n, m, u) && !isInPosList(u, posList))
    {
        ans[0] = true;
    }
    
    if (isLegal(mat, n, m, d) && !isInPosList(d, posList))
    {
        ans[1] = true;
    }
    
    if (isLegal(mat, n, m, l) && !isInPosList(l, posList))
    {
        ans[2] = true;
    }

    if (isLegal(mat, n, m, r) && !isInPosList(r, posList))
    {
        ans[3] = true;
    }
    return ans;
}


bool isInPosList(coord position, coord posList[])
{
    bool ans = false;

    for (int i = 0; posList[i].x != -1 && posList[i].y != -1; i++)
    {
        if (position.x == posList[i].x && position.y == posList[i].y )
        {
            ans = true;
            return ans;
        }
    }
    
    return ans;
}


coord move(coord position, char order)
{
    switch (order)
    {
    case 'u': position.x -= 1; break;
    case 'd': position.x += 1; break;   
    case 'l': position.y -= 1; break;
    case 'r': position.y += 1; break;
    }

    return position;
}

bool isLegal(char mat[][101], int n, int m, coord start)
{
    bool ans = false;

    if(start.x >= 0 && start.x < n && start.y >= 0 && start.y < m)
    {
        if(mat[start.x][start.y] != '#')
        {
            ans = true;
            return ans;
        }
    }
    return ans;
}


