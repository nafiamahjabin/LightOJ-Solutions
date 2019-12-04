#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, n, t, kase=1;
    cin>> t;
    while(t--)
    {
        cin >> x >> y;
        if(x>y)
        {
            n = ((x-y)*4)+(x*4);
        }
        else
        {
            n = y*4;
        }
        printf("Case %d: %d\n",kase++, n+19);
    }
    return 0;
}

