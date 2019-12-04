#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 500000000
ll callForZero(ll n)
{
    ll i, res=0;
    for(i=5; i<=n; i*=5)
    {
        res+=(n/i);
    }

    return res;
}
int main()
{
    ll t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll q;
        scanf("%lld", &q);
        printf("Case %lld: ", cs++);
        ll ans=-1, b=1, e=mx, mi;
        while(b<=e)
        {
            mi=(b+e)/2;
            ll n= callForZero(mi);
            if(n==q)
            {
                ans=mi;
                break;

            }
            else if(n<q) b=mi+1;
            else e= mi-1;

        }
        if(ans==-1) printf("impossible\n");
       else {
            ans-=(ans%5);
            printf("%lld\n", ans);
       }
    }
}
