#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[100006];
int main()
{
    ll t, cs=1, i, j, k, sum, n,man,mny, arr[110];
    scanf("%lld", &t);
    while(t--)
    {
        sum=0;
        scanf("%lld", &n);
        for(i=1; i<=n; i++)
        {
            scanf("%lld", &arr[i]);
            sum+=arr[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0]=1;
        if(n%2!=0)
            man=n/2+1;
        else
            man=n/2;
        if(sum%2!=0)
            mny=sum/2+1;
        else
            mny=sum/2;

        for(i=1; i<=n; i++)
        {
            for(j=mny; j>=1; j--)
            {
                if(arr[i]<=j)
                    dp[j]|=(dp[j-arr[i]]<<1);
            }
        }
        printf("Case %lld: ", cs++);
        if(n==1)
        {
            cout<<0<<" "<<arr[1]<<endl;
            continue;
        }
        ll ans;
        for(i=mny; i>=1; i--)
        {

            if((bool)(dp[i]&(1ll<<n/2)))
            {
                ans=i;
                break;
            }
        }
        if(n%2!=0)
        {

            for(i=mny; i>=1; i--)
            {

                if((bool)(dp[i]&(1ll<<(n/2+1))))
                {
                    ans=max(ans,i);
                    break;
                }
            }

        }
        printf("%lld %lld\n", min(ans, sum-ans), max(ans, sum-ans));
    }
}
