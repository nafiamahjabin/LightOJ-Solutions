#include<bits/stdc++.h>
using namespace std;
int w, k, n;
int dp[110][110], cost[110], nxt[110];

int call(int i, int wt)
{
    if(wt<0)
    {
        return -INT_MAX;
    }

    if(i>=n)
    {
        return 0;
    }


    if(dp[i][wt]!=-1)
        return dp[i][wt];

    int ret1= cost[i]+call(nxt[i], wt-1);
    int ret2= call(i+1, wt);

    return dp[i][wt]= max(ret1, ret2);
}

int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        int arr[110], i, x;
        scanf("%d %d %d", &n, &w, &k);
        for(i=0; i<n; i++)
            cin>>x>>arr[i];
        sort(arr, arr+n);
        for(i=0; i<n; i++)
        {
            int j;
            for(j=i; j<n && (arr[j]-arr[i]<=w); j++);
            nxt[i]=j;
            cost[i]= j-i;
        }
        memset(dp, -1, sizeof(dp));

        printf("Case %d: ", cs++);
        cout<<call(0, k)<<endl;
    }
}
