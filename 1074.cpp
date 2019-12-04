#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 999999999999999
vector<pair<ll, ll> >E;
ll dis[2100], brr[1000000];
ll n, m;
bool check[2100];
void bellmanford(ll src)
{
    ll i, j;
    for(i=1; i<=n; i++)
    {
        dis[i]=MAX;
        check[i]=true;
    }
    dis[src]=0;
    ll l= E.size();
    for(i=1; i<=n-1; i++)
    {
        for(j=0; j<l; j++)
        {
            ll u= E[j].first;
            ll v= E[j].second;
            ll w= brr[j];
            if(dis[u]!=MAX && dis[u]+w< dis[v])
            {
                dis[v]= dis[u]+w;
            }
        }
    }
    for(i=0; i<l; i++)
    {
        ll u= E[i].first;
        ll v= E[i].second;
        ll w= brr[i];
        if(dis[u]!=MAX && dis[u]+w< dis[v])
        {
            dis[v]= dis[u]+w;
            check[v]=false;
            check[u]=false;
        }
    }
}
int main()
{
    ll t, cs=1, x, y, i, q, arr[210];

    scanf("%lld", &t);
    while(t--)
    {
        E.clear();
        scanf("%lld", &n);
        for(i=1; i<=n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        scanf("%lld", &m);
        for(i=0; i<m; i++)
        {
            scanf("%lld %lld", &x, &y);
            brr[i]=((arr[y]-arr[x])*(arr[y]-arr[x])*(arr[y]-arr[x]));
            E.push_back(make_pair(x, y));
        }
        bellmanford(1);
        scanf("%lld", &q);
        printf("Case %lld:\n", cs++);

        while(q--)
        {
            scanf("%lld", &x);
            if(dis[x]<3 || dis[x]==MAX || check[x]==false) printf("?\n");
            else printf("%lld\n", dis[x]);
        }
    }

}

