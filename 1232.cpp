#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
int main()
{
    ll n,t,cs=1, dp[10100],coin[105], i, j, k;
    cin>>t;
    while(t--)
    {
        memset(dp,0, sizeof(dp));
        dp[0]=1;
        cin>>n>>k;
        for(i=0; i<n; i++)
        {
            cin>>coin[i];
        }
        for(i=0; i<n; i++)
        {
            for(j=1; j<=k; j++)
            {
                if(coin[i]<=j)
                {
                    dp[j]= (dp[j]+dp[j-coin[i]])%mod;
                }
            }
        }
        printf("Case %lld: %lld\n", cs++, dp[k]);
    }
}
