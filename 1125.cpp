#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[210][15][100], n, m, d, arr[210];
ll call(ll i, ll j, ll mod)
{
    if(j>=m)
    {
        if(mod==0) return 1;
        return 0;
    }
    if(i>=n) return 0;
    if(dp[i][j][mod]!=-1) return dp[i][j][mod];
    ll ret1= call(i+1, j+1, (mod+arr[i])%d);
    ll ret2= call(i+1, j, mod);
    return dp[i][j][mod]=ret1+ret2;

}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        printf("Case %d:\n", cs++);
        ll q;
        scanf("%lld %lld", &n, &q);
        for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
        while(q--)
        {
            memset(dp, -1, sizeof(dp));
            scanf("%lld %lld", &d, &m);
            printf("%lld\n",call(0,0,0));
        }


    }
}
