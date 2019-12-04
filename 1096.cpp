#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=10007;
vector<vector<int> > multiply(vector<vector<int> >v1, vector<vector<int> >v2)
{
    vector<vector<int> >mat;

    int r1=v1.size();
    int c1=v1[0].size();
    int r2=v2[0].size();
    int temp[100][100]= {0};
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
        vector<int>t;
        for(j=0; j<r2; j++)
        {
            t.push_back(temp[i][j]);
        }
        mat.push_back(t);
    }
    return mat;

}
vector<vector<int> > call(vector<vector<int> >v, ll p)
{
    vector<vector<int> >res;
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
        int a, b, c;
        scanf("%lld %d %d %d", &n, &a, &b, &c);

        if(n<=2) printf("Case %d: 0\n",cs++);

        else
        {
            vector<vector<int> >v;
            vector<int> temp;
            temp.push_back(a);temp.push_back(0);temp.push_back(b);temp.push_back(c);
            v.push_back(temp);
            temp.clear();
            temp.push_back(1);temp.push_back(0);temp.push_back(0);temp.push_back(0);
            v.push_back(temp);
            temp.clear();
            temp.push_back(0);temp.push_back(1);temp.push_back(0);temp.push_back(0);
            v.push_back(temp);
            temp.clear();
            temp.push_back(0);temp.push_back(0);temp.push_back(0);temp.push_back(1);
            v.push_back(temp);

            vector<vector<int> >ans;
            ans=call(v,n-1);

            int r=ans.size();
            int c=ans[0].size(),i;

            printf("Case %d: %d\n",cs++, ans[1][3]);
        }

    }

}
