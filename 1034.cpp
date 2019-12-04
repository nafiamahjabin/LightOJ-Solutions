#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v[10005];
bool vis[10005], ok;
vector<ll>topo;
void dfs(ll n)
{
    vis[n]=1;
    ll l=v[n].size(), i;
    for(i=0; i<l; i++)
    if(vis[v[n][i]]==0) dfs(v[n][i]);
    if(ok) topo.push_back(n);
}
int main()
{
    ll t,a,b, cs=1, i, n, m;
    scanf("%lld", &t);
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(v, 0, sizeof(v));
        topo.clear();
        scanf("%lld %lld", &n, &m);
        while(m--)
        {
            scanf("%lld %lld", &a, &b);
            v[a].push_back(b);
        }
        ok=true;
        for(i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        ok=false;
        ll cnt=0;
        memset(vis, 0, sizeof(vis));
        ll l= topo.size();

        for(i=l-1; i>=0; i--)
        {
            if(!vis[topo[i]])
            {
                cnt++;
                dfs(topo[i]);
            }
        }
        printf("Case %lld: %lld\n", cs++, cnt);
    }
}

