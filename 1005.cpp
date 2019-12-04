#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fact(ll n)
{
    if(n<=1) return 1;
    return n*fact(n-1);

}
int main()
{
    ll n, k, t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        printf("Case %lld: ", cs++);
        if(n<k )
        {
            cout<<0<<endl;
            continue;
        }
        if(k==1)
        {
            cout<<n*n<<endl;
            continue;
        }
        if(k==0)
        {
            cout<<1<<endl;
            continue;
        }
        ll ncr=1, i;
        for(i=n; i>(n-k); i--) ncr*=i;

        ncr/=fact(k);
        ll ans=1;
        for(i=n; i>(n-k); i--) ans*=i;

        cout<<ans*ncr<<endl;
    }

}

