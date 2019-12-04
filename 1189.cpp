#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define N 1000000000000000000
unsigned long long fact[30], f=1;
int in[30];
int main()
{
    ll i=0, j=0;
    fact[j]=1, in[j]=0;
    j++;
    for(i=1; f<=N; i++)
    {
        f*=i;
        if(f<=N)
        {
            fact[j]=f;
            in[j]=i;
            j++;
        }
    }
    f=j;
    ll t, n, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        i=f-1;
        vector<int>ans;
        while(i>=0)
        {
            if(fact[i]<=n)
            {
                n-=fact[i];
                ans.pb(in[i]);
            }
            i--;
        }
        printf("Case %d: ", cs++);
        ll l=ans.size();
        if(n!=0) printf("impossible\n");
        else
        {
            for(i=l-1; i>=1; i--) printf("%d!+",ans[i]);
            printf("%d!\n", ans[0]);
        }

    }

}
