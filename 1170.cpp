#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000000000
#define N 304470
vector<ll>v;
map<ll,int>mp;
ll fact[N+100], m=100000007;
void pre()
{
    for(ll i=2; i<=100000; i++)
    {
        ll p=i*i;
        for(;p<=mx; p*=i)
        {
            if(mp[p]==0 && p>0)
            v.push_back(p);
            mp[p]=1;

        }

    }

  sort(v.begin(), v.end());


}
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
    pre();
    factorial();
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        ll a,b;
        scanf("%lld %lld", &a, &b);
        ll l=lower_bound(v.begin(), v.end(), a)-v.begin();
        ll r= lower_bound(v.begin(), v.end(),b)-v.begin();
        ll n=r-l;

        if(v[r]==b) n++;

        if(n==0)
        {
            printf("Case %d: 0\n", cs++);
            continue;
        }
        if(n==1)
        {
            printf("Case %d: 1\n", cs++);
            continue;
        }
        if(n==2)
        {
            printf("Case %d: 2\n", cs++);
            continue;
        }


        ll ncr=(fact[2*n]*(modInverse(fact[n], m)%m))%m;

         ncr=(ncr*(modInverse(fact[n], m)%m))%m;
         ncr=(ncr*(modInverse(n+1, m)%m))%m;
         printf("Case %d: %lld\n",cs++, ncr);


    }
}
