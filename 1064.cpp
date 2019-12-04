#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n, make,dp[30][200];
ll call(ll i, ll sum)
{
    if(i>n)
    {
        if(sum==make) return 1;
        else return 0;
    }
    if(sum>make) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    ll ans=0;
    for(int j=1; j<=6; j++)
    {
        ans+=call(i+1, sum+j);
    }
    return dp[i][sum]=ans;
}
int main()
{
    ll i, sum, m, t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &m);
        printf("Case %lld: ", cs++);
        if(m==0)
        {
            cout<<1<<endl;
            continue;
        }
        sum=0;
        ll tot=1;
        for(i=1; i<=n; i++) tot*=6;
        if(tot<m) cout<<0<<endl;
        else
        {

            for(i=n; i<m; i++)
            {
                make=i;
                memset(dp,-1, sizeof(dp));
                sum+=call(1, 0);
            }


            sum=tot-sum;

            if(sum==0) {
                cout<<0<<endl;
                continue;
            }

            if(sum==tot) {
                cout<<1<<endl;
                continue;
            }
            cout<<(sum/__gcd(tot, sum))<<"/"<<(tot/__gcd(tot, sum))<<endl;


        }

    }
}
