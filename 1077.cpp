#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, cs=1;
    cin>>t;
    while(t--)
    {
        ll ax,ay, bx,by;
        cin>>ax>>ay>>bx>>by;
        ll dx=abs(ax-bx);
        ll dy=abs(ay-by);
        printf("Case %lld: ", cs++);
        if(dx==0 && dy==0)
        {
            cout<<1<<endl;
            continue;
        }
        if(dx==0) cout<<dy+1<<endl;
        else if(dy==0) cout<<dx+1<<endl;
        else
        {
            dx=dy/__gcd(dx,dy);
            dy= 1+dy/dx;
            cout<<dy<<endl;
        }
    }
}

