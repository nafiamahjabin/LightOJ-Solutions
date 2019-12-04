#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int, int> >v[300005];
ll cnt[300005], ans, node;
bool vis[300005];
ll bfs(ll n)
{
    queue<ll>q;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
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
                cnt[v[n][i].first]= cnt[n]+v[n][i].second;
                if(ans< cnt[v[n][i].first])
                {
                    ans= cnt[v[n][i].first];
                    node=v[n][i].first;
                }
            }
        }
    }

}
int main()
{
    ll n, m, i, j, t, cs=1;
    cin>>t;
    while(t--)
    {
        memset(v,0, sizeof(v));
        cin>>n;
        ll a, b, c;
        for(i=0; i<n-1; i++)
        {
            cin>>a>>b>>c;
            v[a].push_back(make_pair(b,c));
            v[b].push_back(make_pair(a,c));
        }
        bfs(0);
        bfs(node);
        printf("Case %lld: %lld\n", cs++, ans);
    }
}
