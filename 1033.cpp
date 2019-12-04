#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<ll, ll>, ll>dp;
string s;
ll func(ll st, ll en)
{
    if(st>=en) return 0;
    if(dp[make_pair(st,en)]!=0) return dp[make_pair(st,en)];
     if(s[st]==s[en])
    {
        return dp[make_pair(st,en)]=func(st+1, en-1);
    }
    else
    {
        return dp[make_pair(st,en)]=(1+min(func(st+1, en), func(st, en-1)));
    }

}
int main()
{
    ll t, cs=1,i, l;

    cin>>t;
    while(t--)
    {
        s.clear();

        cin>>s;
        l =s.size();
        dp.clear();
        printf("Case %lld: %lld\n", cs++, func(0,l-1));


    }
}
