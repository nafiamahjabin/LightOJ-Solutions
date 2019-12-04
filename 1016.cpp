#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005
map<ll, ll>mp;
ll n, arr[sz], dp[sz], w;
int main()
{
    ll t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &w);
        int i=0;
        vector<ll>v;
        while(n--)
        {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            v.push_back(y);
        }
        sort(v.begin(), v.end());
        n=v.size();
        ll ans=0;
        for(i=0; i<n; i++)
        {
            int j= lower_bound(v.begin(), v.end(), v[i]+w+1)-v.begin();
            ans++;
            i=j-1;
        }
        printf("Case %lld: %lld\n", cs++,ans);
    }
}


