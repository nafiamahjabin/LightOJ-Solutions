#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10][100][100][2],k,l;
vector<int>v;
ll call(int i, int rem, int remDigit, int isSmall)
{
    if(i==l)
    {
        if(rem==remDigit && rem==0) return 1;
        return 0;
    }

    if(dp[i][rem][remDigit][isSmall]!=-1) return dp[i][rem][remDigit][isSmall];

    ll ret=0,sum=0, nm=0;
    int ss=9;
    if(!isSmall) ss= v[i];

    for(int j=0; j<ss; j++)
    {
        ret+=call(i+1, (rem*10+j)%k, (remDigit+j)%k, 1);
    }
    if(isSmall)
        ret+=call(i+1, (rem*10+ss)%k, (remDigit+ss)%k, 1);
    else
        ret+=call(i+1, (rem*10+ss)%k, (remDigit+ss)%k, 0);

    return dp[i][rem][remDigit][isSmall]=ret;


}

ll solve(ll x)
{
    if(x<0 || k>81) return 0;
    v.clear();
    while(x!=0)
    {
        v.push_back(x%10);
        x/=10;
    }
    l=v.size();
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    return call(0,0,0,0);
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        ll n, m;
        scanf("%lld %lld %lld", &n, &m, &k);
        printf("Case %d: %lld\n",cs++, solve(m)- solve(n-1));
    }
}
