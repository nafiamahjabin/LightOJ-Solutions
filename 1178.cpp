#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        double a,b,c,d, ans,x,h;
        cin>>a>>b>>c>>d;
        x= fabs(a-c);
        ans= (x+b+d)/2;
        ans= sqrt(ans*(ans-x)*(ans-b)*(ans-d));
        h= (ans*2)/x;
        ans= (0.5)*h*(a+c);
        printf("Case %d: %lf\n",cs++,ans);
    }
}
