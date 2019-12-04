#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nm 10000.0
ll dp[101][10005], wt, n, cost[110], weight[110];
ll call(ll i, ll sum)
{
    if(i>=n) return 0;


    if(dp[i][sum]!=-1) return dp[i][sum];

    ll ret1=0, ret2=0;

    if(sum+weight[i]<=wt)
    {
        ret1=call(i, sum+weight[i])+cost[i];
    }
    ret2= call(i+1, sum);
    return dp[i][sum]=max(ret1, ret2);
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        ll p;
        cin>>n>>wt;
        for(int i=0; i<n; i++)
        {
            cin>>cost[i]>>p>>weight[i];
            wt-=(p*weight[i]);

        }
        if(wt<0) printf("Case %d: Impossible\n", cs++);
        else if(wt==0) printf("Case %d: 0\n", cs++);
        else
        {
            ll ans=call(0,0);
            printf("Case %d: %lld\n", cs++, ans);
        }
    }
}

