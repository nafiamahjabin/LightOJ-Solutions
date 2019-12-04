#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,d[10005], low[10005], parent[10005], no_of_children[10005], root;
bool vis[10004];
vector<int>v[10050];
vector<pair<int, int> >art;
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
            if(d[n]<low[v[n][i]])
            {
                art.push_back(make_pair(min(n, v[n][i]),max(n, v[n][i])));
            }
            no_of_children[n]++;
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
        art.clear();
        memset(parent, 0, sizeof(parent));
        memset(vis, 0, sizeof(vis));
        memset(v, 0, sizeof(v));
        memset(no_of_children, 0, sizeof(no_of_children));
        t=0;
        root=0;
        int n, m, a, b,i;
        scanf("%d", &n);
        char c;
        for(i=0; i<n;i++)
        {
            scanf("%d (%d)", &a, &m);
            while(m--) {
                cin>>b;
                v[a].push_back(b);
            }
        }

        for(i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                root=i;
                dfs(i);
            }
        }
        sort(art.begin(), art.end());
        int cnt=art.size();

        printf("Case %d:\n", cs++);
        printf("%d critical links\n",cnt);
        for(i=0; i<cnt; i++) cout<<art[i].first<<" - "<<art[i].second<<endl;
    }
}
