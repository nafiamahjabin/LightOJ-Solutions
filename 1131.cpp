#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod;
vector<vector<ll> > multiply(vector<vector<ll> >v1, vector<vector<ll> >v2)
{
    vector<vector<ll> >mat;

    int r1=v1.size();
    int c1=v1[0].size();
    int r2=v2[0].size();
    ll temp[100][100]= {0};
    int i, j, k;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<r2; j++)
        {
            temp[i][j]=0;
            ll sum=0;
            for(k=0; k<c1; k++)
            {
                sum+=(v1[i][k]*v2[k][j]);
                sum%=mod;
            }
            temp[i][j]=sum;

        }
    }
    for(i=0; i<r1; i++)
    {
        vector<ll>t;
        for(j=0; j<r2; j++)
        {
            t.push_back(temp[i][j]);
        }
        mat.push_back(t);
    }
    return mat;

}
vector<vector<ll> > call(vector<vector<ll> >v, ll p)
{
    vector<vector<ll> >res;
    if(p==1) return v;
    if(p%2==0)
    {
        res=call(v,p/2);
        return multiply(res,res);
    }
    else
    {
        res=call(v, p-1);
        return multiply(res,v);
    }

}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        ll a1,q,b1,c1,a2,b2,c2;
        ll f[5], g[5];
        scanf("%lld %lld %lld %lld %lld %lld", &a1, &b1, &c1, &a2, &b2, &c2);
        for(int i=0; i<3; i++) cin>>f[i];
        for(int i=0; i<3; i++) cin>>g[i];
        scanf("%lld", &mod);
        vector<vector<ll> >v;
        vector<vector<ll> >ans;
        vector<ll>temp;
        temp.push_back(a1);temp.push_back(b1);temp.push_back(0);
        temp.push_back(0);temp.push_back(0);temp.push_back(c1);
        v.push_back(temp);
        temp.clear();
        temp.push_back(1);temp.push_back(0);temp.push_back(0);temp.push_back(0);temp.push_back(0);temp.push_back(0);
        v.push_back(temp);
        temp.clear();
        temp.push_back(0);temp.push_back(1); temp.push_back(0); temp.push_back(0); temp.push_back(0);temp.push_back(0);
        v.push_back(temp);
        temp.clear();
        temp.push_back(0);temp.push_back(0);temp.push_back(c2); temp.push_back(a2);temp.push_back(b2);temp.push_back(0);
        v.push_back(temp);
        temp.clear();
        temp.push_back(0);temp.push_back(0);temp.push_back(0);temp.push_back(1);temp.push_back(0);temp.push_back(0);
        v.push_back(temp);
        temp.clear();
        temp.push_back(0);temp.push_back(0);temp.push_back(0);temp.push_back(0);temp.push_back(1);temp.push_back(0);
        v.push_back(temp);
        temp.clear();
        scanf("%lld", &q);
        printf("Case %d:\n", cs++);
        while(q--)
        {
            scanf("%lld", &n);
            if(n<3) {
                printf("%lld %lld\n", f[n]%mod, g[n]%mod);
                continue;
            }
            ans= call(v, n-2);

            ll final_ansf= (ans[0][0]*f[2])%mod+(ans[0][1]*f[1])%mod+(ans[0][2]*f[0])%mod+ (ans[0][3]*g[2])%mod +(ans[0][4]*g[1])%mod +(ans[0][5]*g[0])%mod;
            ll final_ansg= (ans[3][0]*f[2])%mod+(ans[3][1]*f[1])%mod+(ans[3][2]*f[0])%mod+ (ans[3][3]*g[2])%mod +(ans[3][4]*g[1])%mod +(ans[3][5]*g[0])%mod;


            printf("%lld %lld\n", final_ansf%mod, final_ansg%mod);

        }

    }

}
