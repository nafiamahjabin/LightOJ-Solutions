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
        n*=2;
        long long arr[n+5],xr;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        printf("Case %d: ", cs++);

        xr=arr[1]-arr[0]-1;
        for(i=3; i<n; i+=2) xr^=(arr[i]-arr[i-1]-1);
        if(xr==0) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;

    }
}
