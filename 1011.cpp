#include<bits/stdc++.h>
using namespace std;
int dp[20][1<<17], mat[20][20],n, mask[30];
int call(int i, int j)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ret1=0, ret2=0;
    for(int k=0; k<n; k++)
    {
        if(!(j & (1 <<k)))
        ret1= max(ret1, mat[i][k]+call(i+1, j| (1<< k)));
    }
    return dp[i][j]=ret1;
}
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i;
        memset(dp, -1, sizeof(dp));
        for(i=0; i<n; i++)
        {

            for(int j=0; j<n; j++) cin>>mat[i][j];
        }
        cout<<"Case "<<cs++<<": ";
        cout<<call(0,0)<<endl;
    }
}
