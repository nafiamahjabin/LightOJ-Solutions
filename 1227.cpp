#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int n, arr[110],i,p,q,cnt=0,sum=0;
        cin>>n>>p>>q;
        for(i=1; i<=n; i++) cin>>arr[i];
        for(i=1; i<=n; i++)
        {
            if(sum+arr[i]<=q)
            {
                sum+=arr[i];
                cnt++;
                if(cnt==p) break;
            }
            else break;
        }
        cout<<"Case "<<cs++<<": "<<cnt<<endl;
    }
}
