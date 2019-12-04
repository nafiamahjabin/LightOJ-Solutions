#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100][2][2][100][5];
int l;
vector<int>v;

ll call(int i, int isStart, int isSmall, int value, int prev)
{
    if(i==l) return value;

    if(dp[i][isStart][isSmall][value][prev]!=-1) return dp[i][isStart][isSmall][value][prev];

    ll ret=0;
    int ss=1;
    if(!isSmall) ss= v[i];

        for(int j=0; j<=ss; j++)
        {
            ret+= call(i+1, 0, isSmall | ( j< v[i] ), (j==1 && prev==1) + value, j );
        }


    return dp[i][isStart][isSmall][value][prev]=ret;


}

ll solve(ll x)
{
    if(x<0) return 0;
    v.clear();
    while(x!=0)
    {
        v.push_back(x%2);
        x/=2;
    }
    l=v.size();
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    return call(0,1,0,0, 0);
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        printf("Case %d: %lld\n",cs++, solve(n));
    }
}
