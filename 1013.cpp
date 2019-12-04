#include<bits/stdc++.h>
using  namespace std;
#define ll long long
string s1, s2;
ll shortLen,l1,l2,ans[45][45][45], dp[45][45];
ll lcs(ll pos1,ll pos2)
{
    if(pos1<0 || pos2<0) return 0;
    if(dp[pos1][pos2]!=-1) return dp[pos1][pos2];
    if(s1[pos1]==s2[pos2]) return dp[pos1][pos2]=1+lcs(pos1-1, pos2-1);
    if(s1[pos1]!=s2[pos2]) return dp[pos1][pos2]=max(lcs(pos1,pos2-1), lcs(pos1-1, pos2));
}
ll call(ll length, ll pos1, ll pos2)
{
    if(pos1<0){
        length-=(pos2+1);
        if(length==0) return 1;
        else return 0;
    }
    if(pos2<0){
        length-=(pos1+1);
        if(length==0) return 1;
        else return 0;
    }
    if(ans[pos1][pos2][length]!=-1) return ans[pos1][pos2][length];
    if(s1[pos1]==s2[pos2]){
         return ans[pos1][pos2][length]=call(length-1,pos1-1, pos2-1);
    }
    return ans[pos1][pos2][length]=call(length-1,pos1,pos2-1)+ call(length-1,pos1-1, pos2);
}
int main()
{
    ll t, i,cs=1;
    cin>>t;
    while(t--)
    {
        s1.clear();
        s2.clear();
        cin>>s1>>s2;
        l1=s1.size();
        l2=s2.size();
        memset(ans, -1, sizeof(ans));
        memset(dp, -1, sizeof(dp));
        shortLen=l1+l2-lcs(l1-1,l2-1);
        printf("Case %lld: %lld %lld\n",cs++, shortLen, call(shortLen, l1-1, l2-1));
    }
}

