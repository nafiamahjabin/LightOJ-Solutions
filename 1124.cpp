#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 100000007
#define N 1000050
ll fact[1000050], arr[20],sz[40000], add[40000], lar[20];
ll v[40000][12];
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
    if(p%2==0)
    {
        ll r=bigMod(n, p/2,mod)%mod;
        return (r*r)%mod;
    }
    else return (n*bigMod(n,p-1,mod)%mod)%mod;
}
ll modInverse(ll n, ll mod)
{
    return bigMod(n, mod-2, mod);
}
int generate(int n)
{
    memset(v, 0, sizeof(v));
    int vv[20]= {0};
    int psz=1, i,j,jj,ii,k=0;
    for(i=0; i<n; i++) psz*=2;

    for(i=0; i<psz; i++)
    {
        ll sum=0;
        for(j=0, ii=0; j<n; j++)
        {
            if(i&(1<<j))
            {
                vv[ii++]=arr[j];
                sum+=lar[j];
            }
        }
        sort(vv,vv+ii);

        for(j=0,jj=0; j<ii; j++) v[k][jj++]=vv[j];
        sz[k]=jj;
        add[k]=sum;
        k++;
    }
    return k;
}
int main()
{
    factorial();
    ll n, k,cs=1, t;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &k, &n);
        ll i,a,b, sum=0;
        for(i=0; i<k; i++)
        {
            scanf("%lld %lld", &a, &b);
            lar[i]=a;
            arr[i]=b+1;
            sum+=a;
        }
        if(sum>n)
        {
             printf("Case %lld: 0\n", cs++);
             continue;
        }
        ll sumAll=sum, nn=n-sum+k-1,r=k-1;


        ll ans= (fact[nn]%m*(modInverse(fact[r], m)%m)%m*(modInverse(fact[nn-r], m)%m))%m;

        int l=generate(k);
        for(i=1; i<l; i++)
        {
            int len= sz[i];

            sum=0;
            for(int j=0; j<len; j++)
            {
                sum+=v[i][j];
            }

            ll n2=n-(sumAll-add[i])-sum+k-1;

            if(n2-(k-1)<0 || n2<0) continue;

            ll d= (fact[n2]%m*(modInverse(fact[k-1], m)%m)%m*(modInverse(fact[n2-(k-1)], m)%m))%m;

            if(len%2!=0)
            {
                ans-=d;
                if(ans<0) ans= (ans+m)%m;
                else
                ans%=m;
            }
            else ans=(ans+d)%m;
        }
        printf("Case %lld: %lld\n", cs++,ans);
    }


}
