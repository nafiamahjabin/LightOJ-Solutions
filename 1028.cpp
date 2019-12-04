#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000010
vector<int>prime;
bool mark[sz+6];
void sieve()
{
    int root=sqrt(sz)+1;
    for(int i=2; i<=root; i++)
    {
        if(mark[i]==0)
        {
            for(int j=i+i; j<=sz; j+=i)
                mark[j]=1;
        }
    }
    for(int i=2; i<=sz; i++)
        if(mark[i]==0)
            prime.push_back(i);
}
int main()
{
    sieve();
    ll i, t, n,cs=1;
    ll l=prime.size();
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);

        printf("Case %lld: ", cs++);
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        if(n<sz && mark[n]==0)
        {
            printf("1\n");
            continue;
        }
        ll ans=1;
        for(i=0; prime[i]*prime[i]<=n && i<l; i++)
        {
            if(n%prime[i]==0)
            {
                ll cnt=0;
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    cnt++;
                }
                ans*=(cnt+1);
            }
        }
        if(n!=1)
            ans*=2;
        printf("%lld\n", ans-1);
    }
}
