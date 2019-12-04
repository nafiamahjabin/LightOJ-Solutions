#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1010
ll arr[sz],n;
vector<int>v;
ll call(ll c)
{
    if(c<=0) return INT_MAX;
    ll ans=1, cnt=0, sum=0;
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
        v.clear();
        ll k;
        cin>>n>>k;
        n++;
        for(int i=0; i<n; i++) cin>>arr[i];
        ll sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
        }
        ll beg=0,ans=0, en=sum;
        k++;
        while(beg<=en)
        {
            ll mid=(beg+en)/2;
            ll midd=mid-1;
            ll call2= call(mid-1);

            ll call1= call(mid);
            if(call1<=k && call2>k)
            {
                ans=mid;
                break;
            }
            else if(call1<=k) en=mid-1;
            else beg=mid+1;
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        int p=n, q=k; sum=0;
        for(int i=0; i<n; i++)
        {
            if(sum+arr[i]<=ans)
            {
                sum+=arr[i];
                p--;
                q--;
                i++;
                while(sum+arr[i]<=ans && p>q)
                {
                    sum+=arr[i];
                    i++;
                    p--;
                }
                v.push_back(sum);
                sum=0;
                i--;
            }

        }
        for(int i=0; i<v.size(); i++) cout<<v[i]<<endl;


    }

}
