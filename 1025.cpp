#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mark[100],l, dp[100][100];
string s;
ll call(int i, int j)
{
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j] = 1 + call(i+1, j)+call(i, j-1);
    else
    {
        return dp[i][j] = call(i, j-1)+call(i+1, j)- call(i+1,j-1);
    }
}

int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        memset(mark, 0, sizeof(mark));
        cin>>s;
        l = s.size();
    printf("Case %d: ", cs++);
        cout<<call(0, l-1)<<endl;
    }

}
