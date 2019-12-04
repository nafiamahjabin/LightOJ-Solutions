#include<bits/stdc++.h>
using namespace std;
#define Max INT_MAX
#define ll long long int
vector<pair<ll, ll> >v[100010];
map<ll, pair<ll, ll> >path;
bool vis[3][100010];
ll dis[3][100010],nd, minRoad;
struct node{
    ll  t, u, w;
    node(ll a, ll b, ll c){
        t=a,u=b, w=c;
    }
    bool operator < (const node & p)const{
        return p.w<w;
    }
};

void callForPath(ll n)
{
    if(path[n].first==-1)
    {
        minRoad=min(minRoad, path[n].second);
        return ;
    }
    minRoad = min(minRoad, path[n].second);
    callForPath(path[n].first);
}
ll dijkstra(ll n)
{
    ll i;
    minRoad=Max;
    memset(vis, false, sizeof(vis));
    priority_queue<node>q;
    for(i=1; i<=nd; i++)
    {
        dis[1][i]= Max;
        dis[2][i]=Max;
    }
    dis[1][n]=0;
    q.push(node(1,n,0));
    while(q.size())
    {
        node x = q.top();
        q.pop();
        ll b = x.u;
        ll t=x.t;
        if(vis[t][b]) continue;
        else vis[t][b] = true;
        vector<pair<ll, ll> >:: iterator vt;
        for(vt= v[b].begin(); vt!= v[b].end(); vt++)
        {
            int d = dis[t][b]+vt->second;
            if(d<dis[1][vt->first])
            {
                dis[2][vt->first]=dis[1][vt->first];
                q.push(node(2,vt->first,dis[2][vt->first]));
                dis[1][vt->first]=d;
                q.push(node(1, vt->first, d));
                path[vt->first]= make_pair(b, d);
            }
            else if(d>dis[1][vt->first] && d<dis[2][vt->first])
            {
                dis[2][vt->first]=d;
                q.push(node(2, vt->first, d));
            }

        }

    }
    callForPath(nd);
    ll x= dis[2][nd];
    ll z= dis[1][nd]+2*minRoad;

    if(x==dis[1][nd])
        return z;
    return min(x,z);
}
int main()
{
    ll e, t, a, b,cs=1, c, s,d, i,m, j;
    scanf("%lld", &t);
    while(t--)
    {
        path.clear();

        memset(v, 0, sizeof(v));
        scanf("%lld %lld", &nd, &e);
        for(i=1; i<=nd; i++)
            path[i]= make_pair(-1, INT_MAX);

        while(e--)
        {
            scanf("%lld %lld %lld", &a, &b, &c);
            v[a].push_back(make_pair(b, c));
            v[b].push_back(make_pair(a, c));
            path[a] = make_pair(-1,min(path[a].second, c));
            path[b] = make_pair(-1,min(path[b].second, c));
        }
        cout<<"Case "<<cs++<<": "<<dijkstra(1)<<endl;
    }
}
