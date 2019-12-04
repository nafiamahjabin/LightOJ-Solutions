#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int i, n, cnt=0;
        cin>>n;
        int arr[n+5],xr;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]==1) cnt++;
        }
        printf("Case %d: ", cs++);
        if(cnt==n)
        {
            if(n%2==0) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        else
        {
            xr=arr[0];
            for(i=1; i<n; i++) xr^=arr[i];
            if(xr==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }
}
