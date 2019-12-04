#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t, cs=1;
    cin>>t;
    double ox, oy, ax, ay, bx, by,d1, d2,ans;
    while(t--)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        d1= sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
        d2= sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));

        ans = acos((2*d1*d1-d2*d2)/(2*d1*d1));
        ans*=d1;
        printf("Case %d: %lf\n", cs++,ans);
    }
}

