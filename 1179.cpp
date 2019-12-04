#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        ll ans=1;
        for(ll i=2; i<=n; i++)
        {
            ans = (ans+(k-1))%i+1;
        }
        printf("Case %d: %lld\n",cs++,ans);
    }
}
