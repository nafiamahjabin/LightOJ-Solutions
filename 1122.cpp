#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[30][14], dig[30], nm[30], k;
ll l, arr[10], n;

ll call(int i, int prev)
{
    if(dp[i][prev]!=-1) return dp[i][prev];

    if(i==l) return 1;

    int ret=0;
    for(int j=0;j<n; j++)
    {
        if(prev==0 || abs(dig[j]-prev)<=2)
        {
            ret+=call(i+1, dig[j]);
        }
    }
    return dp[i][prev]=ret;
}

ll solve(ll x)
{
    l=x;
    memset(dp, -1, sizeof(dp));
    return call(0,0);
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        ll x,m;
        memset(arr, 0, sizeof(arr));
        scanf("%lld %lld", &n, &m);
        for(int i=0; i<n; i++)
        {
            cin>>x;
            dig[i]=x;
            arr[x]=1;
        }
        printf("Case %d: %lld\n",cs++, solve(m));
    }
}
