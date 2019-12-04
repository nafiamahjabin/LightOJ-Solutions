#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll mod = 1000000007;
vector<ll>prime;
bool mark[N+5];
void sieve()
{
    ll i, root=sqrt(N)+1;
    for(i=2; i<root; i++)
    {
        for(int j=i+i; j<=N; j+=i)
        {
            if(!mark[j]) mark[j]=true;
        }
    }
    for(i=2; i<=N; i++) if(!mark[i]) prime.push_back(i);
}
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
ll flg[N+5]= {0};
int main()
{
    sieve();
    ll l=prime.size();
    ll t, n, m, cs=1;
    scanf("%lld", &t);

    while(t--)
    {
        memset(flg, 0, sizeof(flg));
        vector<ll>vp;
        vp.clear();
        scanf("%lld %lld", &n, &m);
        printf("Case %lld: ", cs++);
        if(m==0 ||n==1)
        {
            printf("1\n");
            continue;
        }
        for(int i=0; prime[i]*prime[i]<=n && i<l; i++)
        {
            if(n%prime[i]==0)
            {
                vp.push_back(prime[i]);
                int cnt=0;
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    cnt++;
                }
                flg[prime[i]]=cnt;
            }
        }
        ll ans=1;
        if(n>N)
        {
            ll a=bigmod(n, m+1);
            a-=1;
            if(a<0) a+=mod;
            a=(a*bigmod(n-1,mod-2))%mod;
            ans=a;
        }
        else if(n!=1)
        {
            vp.push_back(n);
            flg[n]++;
        }
        ll len=vp.size();
        for(int i=0; i<len; i++)
        {
            flg[vp[i]]*=m;
            flg[vp[i]]++;
        }
        for(int i=0; i<len; i++)
        {
            ll x=vp[i];
            ll a= bigmod(x, flg[x]);
            a-=1;
            if(a<0) a+=mod;
            ll b=1;

            if(x-1>1)
            b=bigmod(x-1, mod-2);

            a=(a*b)%mod;

            ans=(ans*a)%mod;
        }
        printf("%lld\n", ans);

    }
}
