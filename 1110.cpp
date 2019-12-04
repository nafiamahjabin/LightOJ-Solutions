#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        string str1, str2;
        cin.ignore();
        cin>>str1>>str2;
        int i, j, len1=str1.size(), len2=str2.size();
        str1= "."+str1;
        str2= "."+str2;

        string dp[len1+5][len2+5];

        for(i=1; i<=len1; i++)
        {
            for(j=1; j<=len2; j++)
            {
                if(str1[i]==str2[j])
                {
                    dp[i][j]= dp[i-1][j-1]+str2[j];
                }
                else
                {
                    int l1= dp[i-1][j].size();
                    int l2= dp[i][j-1].size();
                    if(l1>l2) dp[i][j]= dp[i-1][j];
                    else if(l1<l2) dp[i][j]=dp[i][j-1];
                    else dp[i][j]= min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        if(dp[len1][len2].size()==0)
        cout<<"Case "<<cs++<<": :("<<endl;
        else
        cout<<"Case "<<cs++<<": "<<dp[len1][len2]<<endl;
    }
}
