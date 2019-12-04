#include<bits/stdc++.h>
using namespace std;
vector<int>v[50005];
bool vis[50005];
int dp[50005], cnt;
int dfs(int n)
{
    vis[n]=1;
    cnt=0;
    if(vis[v[n][0]]==0) cnt= dfs(v[n][0])+1;
    vis[n]=0;
    dp[n]=cnt;
    return cnt;

}
int main()
{
    int t, n, cs=1,i;
    scanf("%d", &t);
    while(t--)
    {
        memset(v,0, sizeof(v));
        memset(vis,0, sizeof(vis));
        memset(dp,-1, sizeof(dp));
        dp[0]=0;
        scanf("%d", &n);
        int maxx= -INT_MAX, x, y;
        map<int, int>mp;
        for(i=0; i<n; i++)
        {
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
        }
        int ans;
        for(i=1; i<=n; i++)
        {
            if(dp[i]==-1)
            {
                dfs(i);
            }
            if(dp[i]>maxx)
            {
                maxx=dp[i];
                ans=i;
            }
        }
        printf("Case %d: %d\n", cs++, ans);
    }

}
