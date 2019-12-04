#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[30][2][2][30];
int l;
vector<int>v;

ll call(int i, int isStart, int isSmall, int value)
{
    if(i==l) return value;

    if(dp[i][isStart][isSmall][value]!=-1) return dp[i][isStart][isSmall][value];

    ll ret=0;
    int ss=9;
    if(!isSmall) ss= v[i];

    if(isStart)
    {
        for(int j=1; j<=ss; j++)
        {
            ret+=call(i+1, 0, isSmall | (j < v[i]), (j==0)+value);
        }
        ret+=call(i+1, 1, 1, 0);
    }
    else
    {
        for(int j=0; j<=ss; j++)
        {
            ret+= call(i+1, 0, isSmall | ( j< v[i] ), (j==0) + value );
        }

    }
    return dp[i][isStart][isSmall][value]=ret;


}

ll solve(ll x)
{
    if(x<0) return 0;
    if(x<=9) return 1;
    v.clear();
    while(x!=0)
    {
        v.push_back(x%10);
        x/=10;
    }
    l=v.size();
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    return call(0,1,0,0)+1;
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        ll n, m;
        scanf("%lld %lld", &n, &m);
        printf("Case %d: %lld\n",cs++, solve(m)- solve(n-1));
    }
}
