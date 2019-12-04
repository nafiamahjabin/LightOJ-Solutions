#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,d[10005], low[10005], parent[10005], no_of_children[10005], root;
bool vis[10004];
vector<int>v[10050];
bool art[10004];
void dfs(int n)
{
    t++;
    d[n]=t;
    low[n]=d[n];
    vis[n]=1;
    int i, l=v[n].size();
    for(i=0; i<l; i++)
    {
        if(parent[n]==v[n][i]) {
            continue;
        }
        if(vis[v[n][i]])
        {
            low[n]=min(low[n], d[v[n][i]]);
        }
        if(vis[v[n][i]]==false)
        {
            parent[v[n][i]]=n;
            dfs(v[n][i]);
            low[n]=min(low[n], low[v[n][i]]);
            if(d[n]<=low[v[n][i]] && n!=root)
            {
                art[n]=1;
            }
            no_of_children[n]++;
        }
        if(no_of_children[n]>1 && n==root)
        {
            art[n]=1;
        }
    }
}
int main()
{
    int test, cs=1;
    scanf("%d", &test);
    while(test--)
    {
        memset(d, 0, sizeof(d));
        memset(low, 0, sizeof(low));
        memset(art, 0, sizeof(art));
        memset(parent, 0, sizeof(parent));
        memset(vis, 0, sizeof(vis));
        memset(v, 0, sizeof(v));
        memset(no_of_children, 0, sizeof(no_of_children));
        t=0;
        root=0;
        int n, m, a, b,i;
        scanf("%d %d", &n, &m);
        while(m--)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                root=i;
                dfs(i);
            }
        }
        int cnt=0;
        for(i=1; i<=n; i++)
        {
            if(art[i]) cnt++;

        }
        printf("Case %d: %d\n", cs++,cnt);
    }
}
