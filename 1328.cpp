#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100010
ll mod=1000007;
ll arr[sz], dp[sz];
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        ll k, n, c;
        cin>>k>>c>>n>>arr[0];
        for(int i=1; i<n; i++) arr[i]= (k*arr[i-1]+c)%mod;
        sort(arr,arr+n);
        dp[0]=arr[0];
        for(int i=1; i<n; i++) dp[i]=dp[i-1]+arr[i];

        ll ans=dp[n-1]-n*arr[0];
        for(int i=1; i<n; i++)
        {
            ans+=(dp[n-1]-dp[i-1]-arr[i]*(n-i));
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }
}
