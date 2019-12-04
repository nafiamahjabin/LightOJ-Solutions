#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000003
#define N 1000006
ll fact[1000006];
void factorial()
{
    fact[0]=1;

    for(int i=1; i<N; i++)
    {
        fact[i]=(fact[i-1]*i)%m;
    }
}
ll bigMod(ll n, ll p, ll mod)
{
    if(p==0) return 1;
    if(p%2==0){
        ll r=bigMod(n, p/2,mod)%mod;
        return (r*r)%mod;
    }
    else return (n*bigMod(n,p-1,mod)%mod)%mod;
}
ll modInverse(ll n, ll mod)
{
    return bigMod(n, mod-2, mod);
}
int main()
{
    factorial();
    ll t, cs=1, n, r;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &r);
        printf("Case %lld: ", cs++);
        if(r==0)
        {
            printf("1\n");
            continue;
        }
        printf("%lld\n", (fact[n]*(modInverse(fact[r], m)%m)*(modInverse(fact[n-r], m)%m))%m);

    }
}
