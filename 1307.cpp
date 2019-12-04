#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v;
ll n;
ll bs(ll j, ll x)
{
    ll beg=j+1,en=n-1, m=(beg+en)/2, ans=0;
    while(beg<=en)
    {
        if( v[m]<x && v[m+1]>=x) break;
        if(v[m]>=x) en=m-1;
        else  beg=m+1;
        m=(beg+en)/2;
    }
    ans+=(m-j);

    return ans;
}
int main()
{
    ll t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll i , j, x;
        scanf("%lld", &n);
        v.clear();
        for(i=1; i<=n;i++)
        {
            scanf("%lld", &x);
            v.push_back(x);

        }
        sort(v.begin() , v.end());
        v.push_back(2*v[n-1]);
        ll ans=0;
        for(i=0 ;i< n;i++)
        {
            for(j=i+1;j< n;j++)
            {
                  x= v[i]+v[j];
                  ans+=bs(j, x);
            }
        }
        printf("Case %lld: %lld\n", cs++, ans);
    }
}
