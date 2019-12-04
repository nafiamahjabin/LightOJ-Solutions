#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        ll ans= (x*10)/9;
        printf("Case %d: ", cs++);
        if((ans*9)==(x*10)) printf("%llu %llu\n", ans-1, ans);
        else printf("%llu\n", ans);
    }
}
