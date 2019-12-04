#include<bits/stdc++.h>
using namespace std;
int dp[110][110][110], arr[110], n;
int call(int pos, int l, int r)
{
    if(pos>n || l>n || r>n) return 0;
    if(dp[pos][l][r]!=-1) return dp[pos][l][r];

    if(arr[pos]>=arr[l] && arr[r]==0)  dp[pos][l][r]=max(call(pos+1, pos, r), call(pos+1, l, pos))+1;
    else if(arr[pos]>=arr[l] && arr[pos]<=arr[r])
    {
         dp[pos][l][r]=max(call(pos+1, pos, r), call(pos+1, l, pos))+1;
    }

    dp[pos] [l] [r] = max(dp[pos][l][r], call(pos+1, l, r));

   return dp[pos] [l][r];
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        cin>>n;
        for(int i=1; i<=n; i++) cin>>arr[i];
        cout<<"Case "<<cs++<<": "<<call(1,0,0)<<endl;
    }

}
