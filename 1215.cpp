#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxx 99999999999999
ll lcm,g;
bool check(ll n)
{
    ll l=(g/__gcd(g,n))*n;
    if(l==lcm) return true;
    return false;
}
int main()
{
    ll t,cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll a,b;
        scanf("%lld %lld %lld", &a, &b, &lcm);
        g=(a*b)/__gcd(a,b);
        bool ok=1;
        ll i,ans=maxx, root=sqrt(lcm)+1;
        for(i=1; i<=root; i++)
        {
            if(lcm%i==0)
            {
                if(check(i)) {
                        ans=min(ans, i);
                        break;
                }
                if(check(lcm/i)) ans=min(ans, (lcm/i));

            }
        }
        if(ans==maxx) printf("Case %lld: impossible\n", cs++);
        else printf("Case %lld: %lld\n", cs++,ans);
    }
}
