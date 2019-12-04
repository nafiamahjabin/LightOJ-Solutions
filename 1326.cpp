#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 10056
ll arr[1001][1001], dp[1003];
void ncr()
{
    arr[0][0]=1;
    for(int i=1; i<=1000; i++)
    {
        arr[i][0]=1;
        for(int j=i; j>0; j--)
        {
            arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%m;
        }

    }

}
int main()
{
    ncr();
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=1000; i++)
    for(int j=1; j<=i; j++)
    {
        dp[i]=(dp[i]+(arr[i][j]*dp[i-j])%m)%m;
    }
    ll t, cs=1, i,n;
    scanf("%lld", &t);
    while(t--)
    {

        scanf("%lld", &n);
        printf("Case %lld: %lld\n", cs++, dp[n]);
    }
}
