#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, cs=1;
    cin>>t;
    while(t--)
    {
        ll n, arr[100005],in, i, maxx=0;
        cin>>n;
        for(i=0; i<n; i++) cin>>arr[i];
        maxx=arr[0], in=0;
        for(i=1; i<n; i++)
        {
            ll d=arr[i]-arr[i-1];
            if(d>maxx)
            {
                maxx=d;
                in=i;
            }
        }
        ll k=maxx,ans=maxx;
        for(i=in+1; i<n; i++)
        {
            ll d=arr[i]-arr[i-1];
            if(d==maxx)
            {
                ans++;
                break;
            }
            if(d==k-1) k--;
            if(k==0)
            {
                ans++;
                break;
            }
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }
}
