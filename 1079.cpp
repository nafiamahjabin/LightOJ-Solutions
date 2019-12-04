#include<bits/stdc++.h>
using namespace std;
#define sz 10000
double weight[110], dpd[105][sz+5];
int dp[105][sz+5], cost[110];
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int i,n, sum=0;
        double p;
        cin>>p>>n;
        memset(dpd, 0.0, sizeof(dpd));
        memset(dp, 0, sizeof(dp));
        for(i=1; i<=n; i++)
        {
            cin>>cost[i]>>weight[i];
            sum+=cost[i];
        }
        for(i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(j<cost[i])
                {
                    dp[i][j]=dp[i-1][j];
                    dpd[i][j]=dpd[i-1][j];
                }

                else
                {
                    int x= j- cost[i];

                    double d = dpd[i-1][x]+((1.0- dpd[i-1][x])*weight[i]);

                    if(d<p)
                    {
                        if((dp[i-1][x]+cost[i])>dp[i-1][j])
                        {
                            dp[i][j]= dp[i-1][x]+cost[i];
                            dpd[i][j]= d;
                        }
                        else if((dp[i-1][x]+cost[i])==dp[i-1][j])
                        {
                            if(d<dpd[i-1][j])
                            {
                                dp[i][j]= (dp[i-1][x]+cost[i]);
                                dpd[i][j]=d;
                            }
                            else
                            {
                                dp[i][j]= dp[i-1][j];
                                dpd[i][j]= dpd[i-1][j];
                            }
                        }
                        else
                        {
                            dp[i][j]=dp[i-1][j];
                            dpd[i][j]=dpd[i-1][j];
                        }
                    }
                    else
                    {
                        if(dp[i][j-1]>dp[i-1][j])
                        {
                            dp[i][j]=dp[i][j-1];
                            dpd[i][j]=dpd[i][j-1];
                        }
                        else if(dp[i][j-1]==dp[i-1][j])
                        {
                            if(dpd[i][j-1]<dpd[i-1][j])
                            {
                                dp[i][j]= dp[i][j-1];
                                dpd[i][j]= dpd[i][j-1];
                            }
                            else
                            {
                                dp[i][j]= dp[i-1][j];
                                dpd[i][j]= dpd[i-1][j];
                            }

                        }
                        else
                        {
                            dp[i][j]= dp[i-1][j];
                            dpd[i][j]= dpd[i-1][j];
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",cs++, dp[n][sum]);
    }
}
