#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll v[40005][20];
ll arr[20], n,size[40005];
int generate()
{
    memset(v, 0, sizeof(v));
    int vv[20]= {0};
    int psz=1, i,j,jj,ii,k=0;
    for(i=0; i<n; i++)
        psz*=2;

    for(i=0; i<psz; i++)
    {
        for(j=0, ii=0; j<n; j++)
        {
            if(i&(1<<j))
                vv[ii++]=arr[j];
        }
        sort(vv,vv+ii);


        for(j=0,jj=0; j<ii; j++)
            v[k][jj++]=vv[j];
        size[k]=jj;
        k++;

    }
    return k;
}
int main()
{
    ll t, cs=1, year;
    cin>>t;
    while(t--)
    {
        cin>>year>>n;
        ll ans=0;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int l=generate();
        for(int i=1; i<l; i++)
        {
            int len=size[i];
            ll lcm=1;
            for(int j=0; j<len; j++)
            {
                lcm= (lcm*v[i][j])/__gcd(lcm,v[i][j]);
            }
            if(len%2==0)
            {
                ans-=(year/lcm);
            }
            else
                ans+=(year/lcm);

        }
        printf("Case %lld: %lld\n", cs++,year-ans);
    }

}
