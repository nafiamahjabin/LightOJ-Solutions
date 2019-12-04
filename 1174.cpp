#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt1[110], cnt2[110];
vector<ll>v[110];
bool vis[110];
void bfs(ll a)
{
    memset(vis, 0, sizeof(vis));
    memset(cnt1, 0, sizeof(cnt1));
    queue<ll>q;
    q.push(a);
    while(q.size())
    {
        a=q.front();
        q.pop();
        vis[a]=1;
        int i, l=v[a].size();
        for(i=0; i<l; i++)
        {
            if(vis[v[a][i]]==0)
            {
                q.push(v[a][i]);
                vis[v[a][i]]=1;
                cnt1[v[a][i]]= cnt1[a]+1;
            }
        }
    }
}
void bfs2(ll a)
{
    memset(vis, 0, sizeof(vis));
    memset(cnt2, 0, sizeof(cnt2));
    queue<ll>q;
    q.push(a);
    while(q.size())
    {
        a=q.front();
        q.pop();
        vis[a]=1;
        int i, l=v[a].size();
        for(i=0; i<l; i++)
        {
            if(vis[v[a][i]]==0)
            {
                q.push(v[a][i]);
                vis[v[a][i]]=1;
                cnt2[v[a][i]]= cnt2[a]+1;
            }
        }
    }
}
int main()
{
    ll r,t, cs=1, i, j, a, b, n;
    cin>>t;
    while(t--)
    {
        memset(v, 0, sizeof(v));
        cin>>n;
        cin>>r;
        while(r--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cin>>a>>b;
        bfs(a);
        bfs2(b);
        ll ans=0;
        for(i=0; i<n; i++)
        {
            ans= max(ans, cnt1[i]+cnt2[i]);
        }
        printf("Case %lld: %lld\n", cs++, ans);
    }
}
