
#include<iostream>

using namespace std;

//函数声明
int rightCount(int rank[], int count[]);
int printArray(int a[], int n);
int heapPermutation(int a[], int size, int n);

// 四大湖
int main()
{

    int rank[4];

    //输入数组
    int a[4] = {1, 2, 3, 4};

    //排列可能性，判断并输出 
    heapPermutation(a, 4, 4); 


// good luck:)
    return 0;
}


int rightCount(int rank[], int ans[])
{
   int count = 0;

   for (int i = 0; i < 4; ++i)
   {
       if (rank[i] == ans[i])
       {
           ++count;
       }
   }

    return count;
}

int printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << endl;
    }
}


// Generating permutation using Heap Algorithm 
int heapPermutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if (size == 1) 
    { 

        int ans[4][4] = {{3, 1, 0, 4}, {2, 4, 3, 1}, {0, 3, 0, 4}, {1, 3, 4, 2}}; //a, b, c, d 命题
        int result[4] = {0};                                                      //a, b, c, d 正确个数
 
        for (int j = 0; j < 4; ++j)
        {
            result[j] = rightCount(a, ans[j]);
        }

        if (result[0] == 1 && result[1] == 1 && result[2] == 1 && result[3] == 1)
        {
            printArray(a, 4); 
        }

    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
  
        // if size is odd, swap first and last 
        // element 
        if (size%2==1) 
            swap(a[0], a[size-1]); 
  
        // If size is even, swap ith and last 
        // element 
        else
            swap(a[i], a[size-1]); 
    }

    return 0; 
} 