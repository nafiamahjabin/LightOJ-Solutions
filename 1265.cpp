#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pre[1005];
void nCr()
{
    ll n=1001,r=2;
    ll C[4];
    memset(C,0,sizeof(C));
    C[0]=1;
    for(ll i =1; i <=n; i ++)
    {
        for(ll j=min(i, r); j>0; j--)
            C[j]=C[j]+C[j-1];
        pre[i ]=C[r];
    }
}
int main()
{
    nCr();
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        double ans=1.0;
        cout<<"Case "<<cs++<<": ";
        if(n%2!=0)
        {
            cout<<0<<endl;
            continue;
        }
        while(n!=0)
        {
            ans*=(double)((double)pre[n]/(double)pre[n+1]);
            n-=2;
        }
        cout<<ans<<endl;
    }
}
