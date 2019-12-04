#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000006
ll five[mx+4];
ll two[mx+4];
void pre()
{
    ll i, f=0, t=0;
    for(i=1; i<=mx; i++)
    {
        ll x=i;
        if(x%2==0)
        {
            int cnt=0;
            while(x%2==0)
            {
                x/=2;
                cnt++;
            }
            t+=cnt;

        }
        x=i;
        if(x%5==0)
        {
            int cnt=0;
            while(x%5==0)
            {
                x/=5;
                cnt++;
            }
            f+=cnt;

        }
        five[i]=f;
        two[i]=t;
    }

}
ll factorise(ll n, ll p)
{
    int cnt=0;
    while(n%p==0)
    {
        n/=p;
        cnt++;
    }
    return cnt;
}
int main()
{
    pre();
    ll t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll n, r,p,q;
        scanf("%lld %lld %lld %lld", &n, &r, &p, &q);
        ll twoForNcr=0, fiveForNcr=0;
        if(n>=r)
        {
            twoForNcr= two[n]-(two[r]+two[n-r]);
            fiveForNcr= five[n]-(five[r]+five[n-r]);
        }
        twoForNcr+=(factorise(p,2)*q);
        fiveForNcr+=(factorise(p, 5)*q);
        printf("Case %lld: %lld\n",cs++, min(twoForNcr, fiveForNcr));
    }
}
