#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1010
ll arr[sz],n;
ll call(ll c)
{
    if(c<=0) return INT_MAX;
    ll ans=1, sum=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>c) return INT_MAX;
        if(sum+arr[i]<=c)
        {
            sum+=arr[i];
        }
        else
        {
            ans++;
            sum=arr[i];
        }
    }
    return ans;
}
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>arr[i];
        ll sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
        }
        ll beg=0,ans=0, en=sum;
        while(beg<=en)
        {
            ll mid=(beg+en)/2;
            ll midd=mid-1;
            ll call1= call(mid);
            ll call2= call(mid-1);

            if(call1<=k && call2>k)
            {
                ans=mid;
                break;
            }
            else if(call1<=k) en=mid-1;
            else beg=mid+1;
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;



    }

}
