#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
bool visited[sz];
vector<pair<int, int> >g[sz];
int dis[sz];
int L[sz];
int T[sz];
int P[sz][25];
int Max[sz][25];
struct st
{
    ll a, b, w;

};
st arr[sz];
bool cmp(st aa, st bb)
{
    return aa.w<bb.w;
}
ll parent[sz];
ll find_parent(ll n)
{
    if(parent[n]==n) return n;
    return parent[n]=find_parent(parent[n]);
}
void setUnion(ll u, ll v)
{
    u= find_parent(u);
    v= find_parent(v);

    if(u!=v)
    parent[v]=u;
}
void miNst(ll n, ll e)
{
    int i, j;
    for(i=0; i<=n; i++) parent[i]=i;
    for(i=0; i<e; i++)
    {
        if(find_parent(arr[i].a)!=find_parent(arr[i].b))
        {
            g[arr[i].a].push_back(make_pair(arr[i].b, arr[i].w));
            g[arr[i].b].push_back(make_pair(arr[i].a, arr[i].w));
            setUnion(arr[i].a, arr[i].b);
        }
    }
}
void dfs(ll from,ll u,ll dep)
{
    T[u]=from;
    L[u]=dep;
    visited[u]=1;
    for(ll i=0; i<(ll)g[u].size(); i++)
    {
        ll v=g[u][i].first;
        if(visited[v]) continue;
        dis[v]= g[u][i].second;
        dfs(u,v,dep+1);
    }
}

int lca_query(ll N, ll p, ll q)
{
    int log, i;

    if (L[p] < L[q]) swap(p,q);

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

    }
    int maxV = -INT_MAX;
    for (i = log; i >= 0; i--)
    {
        if (L[p] - (1 << i) >= L[q])
        {
            maxV = max(maxV, Max[p][i]);
            p = P[p][i];

        }
    }

    if (p == q)
    {
        return maxV;
    }
    int flg2= -INT_MAX;
    for (i = log; i >= 0; i--)
    {

        if (P[p][i] != -1 && P[p][i] != P[q][i])
        {
            maxV= max(maxV, max(Max[p][i], Max[q][i]));
            p = P[p][i], q = P[q][i];
        }

        else if(P[p][i]!=-1 && P[p][i]==P[q][i])
        {
            flg2= max(Max[p][i], Max[q][i]);
        }
    }
    return max(flg2, maxV);

}

void lca_init(ll N)
{
    memset (P,-1,sizeof(P));
    int i, j;
    for (i = 0; i < N; i++)
    {
        P[i][0] = T[i];
        Max[i][0] = dis[i];
    }
    for (j = 1; 1<<j < N; j++)
    {
        int maxV = -INT_MAX;
        for (i = 1; i < N; i++)
        {

            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
                maxV = max(Max[P[i][j-1]][j-1], Max[i][j-1]);
                Max[i][j] = maxV;
            }
            else
            {
                Max[i][j] = Max[i][j-1];
            }
        }
    }
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        int nd, e, i,q,a,b;
        memset(g, 0, sizeof(g));
        scanf("%d %d", &nd, &e);

        for(i=0; i<e; i++)
        {
            scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].w);
        }
        sort(arr, arr+e, cmp);
        miNst(nd, e);

        memset(visited, 0, sizeof(visited));
        memset(T, 0, sizeof(T));
        memset(L, 0, sizeof(L));
        for(i=0; i<sz; i++) dis[i]=-INT_MAX;

        scanf("%d", &q);

        dfs(-1, 1, 0);

        lca_init(nd+1);

        printf("Case %d:\n", cs++);

        while(q--)
        {
            scanf("%d %d", &a, &b);
            int ans = lca_query(nd+1, a, b);
            printf("%d\n", ans);
        }

    }
}
