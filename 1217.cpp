#include<bits/stdc++.h>
using namespace std;
int a[1010],dp[1010][5],n;
int call(int i, int one)
{
    if(i>=n) return 0;
    if(i==n-1 && one==1) return 0;
    if(dp[i][one]!=-1) return dp[i][one];
    int x=call(i+1,one);
    if(i==0) one=1;
    int y=call(i+2,one)+a[i];
    return dp[i][one]=max(x,y);

}
int main()
{
    int t,  cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++) cin>>a[i];
        cout<<"Case "<<cs++<<": "<<call(0,0)<<endl;
    }

}
