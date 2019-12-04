#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
ll coin[60],n,k,dp[60][1000], occ[60];

ll call(ll i, ll amount)
{
    if(i==n)
    {
        if(amount==0){
         return 1;
        }
        else return 0;
    }
    if(amount==0) return 1;
    else if(amount<0) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];
    ll ret1=0;
    for(int j=0; j<=occ[i]; j++){
        ret1=(ret1+call(i+1,amount-coin[i]*j))%mod;
    }

    return dp[i][amount]=ret1;

}
int main()
{
    ll i,t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &n, &k);

        for(i=0; i<n; i++) scanf("%lld", &coin[i]);
        for(i=0; i<n; i++) scanf("%lld", &occ[i]);
        printf("Case %lld: ", cs++);
        cout<<call(0, k)<<endl;
    }
}
