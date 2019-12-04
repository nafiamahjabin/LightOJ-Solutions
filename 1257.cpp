#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int, int> >v[30010];
ll cnt[3][30010], ans, node;
bool vis[30010];
ll bfs(ll n, int in)
{
    queue<ll>q;
    memset(vis, 0, sizeof(vis));
    memset(cnt[in], 0, sizeof(cnt[in]));
    ans=-INT_MAX;
    q.push(n);
    while(q.size())
    {
        n=q.front();
        q.pop();
        vis[n]=1;
        ll  l=v[n].size();
        for(ll i=0; i<l; i++)
        {
            if(vis[v[n][i].first]==0)
            {
                vis[v[n][i].first]=1;
                q.push(v[n][i].first);
                cnt[in][v[n][i].first]= cnt[in][n]+v[n][i].second;
                if(ans< cnt[in][v[n][i].first])
                {
                    ans= cnt[in][v[n][i].first];
                    node=v[n][i].first;
                }
            }
        }
    }

}
int main()
{
    ll n, m, i, j, t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        memset(v,0, sizeof(v));
        //cin>>n;
        scanf("%lld", &n);
        ll a, b, c;
        for(i=0; i<n-1; i++)
        {
            scanf("%lld %lld %lld", &a, &b, &c);
            v[a].push_back(make_pair(b,c));
            v[b].push_back(make_pair(a,c));
        }
        bfs(0, 0);
        ll node1=node;
        bfs(node1, 1);
        ll node2=node;
        bfs(node2, 2);
        printf("Case %lld:\n", cs++);
        for(i=0; i<n; i++)
        {
            printf("%lld\n", max(cnt[1][i], cnt[2][i]));
        }
    }
}
