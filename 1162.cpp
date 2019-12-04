#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100002
bool visited[mx];
int nd;
int dis[mx], L[mx];
int P[mx][25];
int Min[mx][25], Max[mx][25], ansMax, ansMin;
int T[mx];
vector<pair<ll, ll> >g[mx];
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

void lca_query(ll N, ll p, ll q)
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
    int minV = INT_MAX;
    int maxV = -INT_MAX;
    for (i = log; i >= 0; i--)
    {
        if (L[p] - (1 << i) >= L[q])
        {
            minV = min(minV, Min[p][i]);
            maxV = max(maxV, Max[p][i]);
            p = P[p][i];

        }
    }

    if (p == q)
    {
        ansMax = maxV;
        ansMin = minV;
        return ;
    }
    int flg1= INT_MAX;
    int flg2= -INT_MAX;
    for (i = log; i >= 0; i--)
    {

        if (P[p][i] != -1 && P[p][i] != P[q][i])
        {
            minV= min(minV, min(Min[p][i], Min[q][i]));
            maxV= max(maxV, max(Max[p][i], Max[q][i]));
            p = P[p][i], q = P[q][i];
        }

        else if(P[p][i]!=-1 && P[p][i]==P[q][i])
        {
            flg1=  min(Min[p][i], Min[q][i]);
            flg2= max(Max[p][i], Max[q][i]);
        }
    }
    ansMax = max(flg2, maxV);
    ansMin = min(flg1, minV);
}

void lca_init(ll N)
{
    memset (P,-1,sizeof(P));
    int i, j;
    for (i = 0; i < N; i++)
    {
        P[i][0] = T[i];
        Min[i][0] = dis[i];
        if(dis[i]!=INT_MAX)
            Max[i][0] = dis[i];
        else Max[i][0] = - INT_MAX;
    }
    for (j = 1; 1<<j < N; j++)
    {
        int minV = INT_MAX;
        int maxV = -INT_MAX;
        for (i = 1; i < N; i++)
        {

            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
                minV = min(Min[P[i][j-1]][j-1],Min[i][j-1]);
                maxV = max(Max[P[i][j-1]][j-1], Max[i][j-1]);
                Min[i][j] = minV;
                Max[i][j] = maxV;
            }
            else
            {
                Min[i][j] = Min[i][j-1];
                Max[i][j] = Max[i][j-1];
            }
        }
    }
}
int main()
{
    int t, e, a, b,c, q,i,cs=1,j;
    scanf("%d", &t);
    while( t-- )
    {
        memset(g, 0, sizeof(g));
        scanf("%d", &nd);
        e = nd-1;
        while(e--)
        {
            scanf("%d %d %d", &a, &b, &c);
            g[a].push_back(make_pair(b,c));
            g[b].push_back(make_pair(a,c));
        }
        memset(visited, 0, sizeof(visited));
        memset(T, 0, sizeof(T));
        memset(L, 0, sizeof(L));
        for(i=0; i<mx; i++) dis[i]=INT_MAX;

        scanf("%d", &q);

        dfs(-1, 1, 0);

        lca_init(nd+1);

        printf("Case %d:\n", cs++);

        while(q--)
        {
            scanf("%d %d", &a, &b);
            lca_query(nd+1, a, b);
            printf("%d %d\n", ansMin, ansMax);
        }


    }
    return 0;

}
