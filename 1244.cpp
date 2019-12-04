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
    ll t,cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll n;
        mod=10007;
        scanf("%lld", &n);
        ll f[]= {0,1,2,5};
        if(n<4)
        {
            printf("Case %lld: %lld\n", cs++,f[n]);
            continue;
        }
        vector<vector<ll> >v;
        vector<ll>temp;
        temp.push_back(2);temp.push_back(0);temp.push_back(1);
        v.push_back(temp);
        temp.clear();
        temp.push_back(1);temp.push_back(0);temp.push_back(0);
        v.push_back(temp);
        temp.clear();temp.push_back(0);temp.push_back(1);temp.push_back(0);
        v.push_back(temp);
        temp.clear();
        vector<vector<ll> >ans;
        ans=call(v,n-3);
        printf("Case %lld: ", cs++);
        ll final_ans= (ans[0][0]*f[3])%mod+(ans[0][1]*f[2])%mod+(ans[0][2]*f[1])%mod;
        printf("%lld\n",final_ans%mod);
    }

}
