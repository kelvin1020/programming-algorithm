#include<iostream>
using namespace std;
int main(){

    int a;
    int b[5];
    int ans;
    cin >> a >> b[0] >> b[1] >> b[2] >> b[3] >> b[4];

    for (int i = 0; i < 5; ++i)
    {
        if (b[i] >= a)
        {
            b[i] = 0;
        }

    }

    ans = b[0] + b[1] + b[2] + b[3] + b[4];

    cout << ans << endl;
    return 0;
}