#include<bits/stdc++.h>
using namespace std;
int dp[60][10][10], l;
string s;
bool isV(char c)
{
    if(c=='A' || c=='E'|| c=='I'|| c=='O'|| c=='U') return true;
    return false;
}
int call(int i, int c, int v)
{
    if(i==l) return 2;
    if(dp[i][c][v]!=-1) return dp[i][c][v];
    int ret1=0, ret2=0;
    if(s[i]=='?')
    {
        if(c>=4) ret1=1;
        else ret1= call(i+1, min(c+1, 5), 0);

        if(v>=2) ret2=1;
        else ret2= call(i+1, 0, min(v+1, 3));
        return dp[i][c][v]= ret1 | ret2;
    }

    if(s[i]=='A')
    {
        if(v>=2)
        {
            return dp[i][c][v] = 1;
            return dp[i][c][v] = call(i+1,0, min(v+1, 3));
        }
        else return dp[i][c][v]= call(i+1, 0, v+1);
    }
    if(c>=4)
    {
        return dp[i][c][v]=1;
        return dp[i][c][v] = call(i+1, min(c+1, 5), 0);
    }
    else return  dp[i][c][v]= call(i+1, c+1, 0);
}
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        cin>>s;
        l=s.size();
        for(int i=0; i<l; i++)
        {
            if(isV(s[i])) s[i]='A';
            else if(s[i]!='?') s[i]='B';
        }
        int res= call(0,0,0);
        printf("Case %d: ", cs++);
        if(res==1)
        {
            cout<<"BAD"<<endl;
        }
        else if(res==2) cout<<"GOOD"<<endl;
        else cout<<"MIXED"<<endl;
    }
}
