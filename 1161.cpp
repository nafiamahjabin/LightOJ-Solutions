#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll fact[100007], arr[100005], dp[100005], f[100005];
void nCr()
{

    ll n=N,r=4;
    ll C[r+1];

    memset(C, 0, sizeof(C));

    C[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1]);
        fact[i]=C[r];
    }
}

ll calc(ll nn)
{
    ll r=4;
    if(nn<r) return 0;
    return fact[nn];
}
int main()
{
    nCr();

    ll t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        memset(f,0,sizeof(f));
        memset(dp,0,sizeof(dp));
        ll n, i, maxx=0;
        scanf("%lld", &n);
        for(i=0; i<n; i++)
        {
            scanf("%lld", &arr[i]);
            maxx=max(maxx, arr[i]);
        }
        for(i=0; i<n; i++)
        {
            ll j;
            for(j=1; j*j<=arr[i]; j++)
            {
                if(arr[i]%j==0)
                {
                    f[j]++;
                    if((arr[i]/j)!=j) f[arr[i]/j]++;
                }
            }
        }
        for(i=maxx; i>=1; i--)
        {
            dp[i]=calc(f[i]);
            for(ll j=i+i; j<=maxx; j+=i)
            {
                dp[i]-=dp[j];
            }

        }
        printf("Case %lld: %lld\n", cs++,dp[1]);

    }

}
