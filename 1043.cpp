#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    double a ,b ,c, r, ans;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>r;
        ans= sqrt(r/(r+1));
        ans = ans*a;
        printf("Case %d: %lf\n", cs++, ans);


    }
}

