#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, q, x, l, v,t,cs=1,arr[100005], sum[100005], i;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &q);
        memset(sum,0,sizeof(sum));

        for(i=1; i<=n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        sum[1]=arr[1];
        for(i=2; i<=n; i++)
        {
            sum[i]+=(arr[i]+sum[i-1]);
        }
        ll ans=0;
        for(i=1; i<n; i++)
        {

            ans+=(((n-i)*arr[i])-(sum[n]-sum[i]));
        }
        printf("Case %lld:\n", cs++);
        while(q--)
        {
            scanf("%lld", &x);
            if(x==1)
            {
                printf("%lld\n", ans);
            }
            else
            {
                scanf("%lld %lld", &l, &v);
                ll dif=arr[l+1]-v;
                arr[l+1]=v;
                ll right=n-(l+1);

                ans-=(right*dif);
                ans+=(l*dif);
            }

        }
    }
}

