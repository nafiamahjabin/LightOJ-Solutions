#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll n, i;
        scanf("%lld", &n);
        ll root=sqrt(n), ans=0;
        for(i=2; i<=root; i++)
        {
            ll j=n/i;
            ans+=(i*(j-i));
            ans+=(((j+i)*(j-i+1))/2);
        }
        printf("Case %lld: %lld\n", cs++,ans);
    }
}
