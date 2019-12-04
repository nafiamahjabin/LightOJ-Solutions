#include<bits/stdc++.h>
using namespace std;
int arr[50+6], brr[50+5], dp[60][60];
int call(int i, int j)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(arr[i]>brr[j]) return dp[i][j]=2+call(i-1, j-1);
    else if(arr[i]<brr[j]) return dp[i][j]= call(i, j-1);
    else
    {
        int ret1= 1+call(i-1, j-1);
        int ret2 = call(i, j-1);
        return dp[i][j] = max(ret1, ret2);
    }
}
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        int n, i;
        cin>>n;
        for(i=0; i<n; i++) cin>>arr[i];
        for(i=0; i<n; i++) cin>>brr[i];
        sort(arr, arr+n);
        sort(brr, brr+n);
        cout<<"Case "<<cs++<<": ";
        int sum=  call(n-1, n-1);
        cout<<sum<<endl;
    }
}
