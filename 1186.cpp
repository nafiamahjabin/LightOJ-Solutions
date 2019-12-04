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

        long long arr[n+5],brr[n+5] ,xr;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(i=0; i<n; i++)
        {
            cin>>brr[i];
        }
        printf("Case %d: ", cs++);

        xr=abs(brr[0]-arr[0]-1);
        for(i=1; i<n; i++) xr^=abs(brr[i]-arr[i]-1);
        if(xr==0) cout<<"black wins"<<endl;
        else cout<<"white wins"<<endl;

    }
}
