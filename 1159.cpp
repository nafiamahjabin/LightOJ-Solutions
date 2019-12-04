#include<bits/stdc++.h>
using namespace std;
int dp[56][56][56];
int len1, len2, len3;
string a, b, c;

int call(int i, int j, int k)
{
    if(i>=len1 || j>=len2 || k>=len3) return 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(a[i]==b[j] && b[j]==c[k])
    {
       return  dp[i][j][k]= 1 + call(i+1, j+1, k+1);
    }
    else
    {
        int ret1= max(call(i+1,j,k), call(i, j+1, k));
        ret1= max(ret1, call(i, j, k+1));
        return dp[i][j][k]=ret1;
    }

}
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        getchar();
        memset(dp, -1, sizeof(dp));
        cin>>a>>b>>c;
        len1= a.size();
        len2= b.size();
        len3= c.size();
        printf("Case %d: ", cs++);
        cout<<call(0,0,0)<<endl;
    }
}
