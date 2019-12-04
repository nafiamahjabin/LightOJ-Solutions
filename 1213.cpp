#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll mod ;

ll bigmod(ll b, ll p)
{
    if(p==0) return 1;
    if(p%2)
    {
        return (b*bigmod(b, p-1))%mod;
    }
    else
    {
        ll res= bigmod(b, p/2)%mod;
        return (res*res)%mod;
    }

}
int main()
{
    ll t,cs=1,n,k,x;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &n, &k, &mod);
        ll sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lld", &x);
            sum=(sum+x)%mod;
        }
        sum= (bigmod(n, k-1)*sum)%mod;
        sum= (sum*k%mod)%mod;
        printf("Case %lld: %lld\n", cs++,sum);
    }
}
