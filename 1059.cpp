#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
struct st
{
    int a, b, w;

};
st arr[1000005];
vector<int>v[100005];
bool cmp(st aa, st bb)
{
    return aa.w<bb.w;
}
int parent[100010], n, e,d, cost, ans;
int find_parent(int n)
{
    if(parent[n]==n) return n;
    return parent[n]=find_parent(parent[n]);
}
void setUnion(int u, int v)
{
    u= find_parent(u);
    v= find_parent(v);

    if(u!=v)
        parent[v]=u;
}
void miNst()
{
    int i;
    cost=0, ans=0;
    for(i=0; i<=n; i++) parent[i]=i;
    for(i=0; i<e; i++)
    {
        if(find_parent(arr[i].a)!=find_parent(arr[i].b))
        {
            if(arr[i].w<d)
                cost+=arr[i].w;
            else ans++;
            setUnion(arr[i].a, arr[i].b);
            v[arr[i].a].push_back(arr[i].b);
            v[arr[i].b].push_back(arr[i].a);
        }
    }
}
bool vis[100005];
void dfs(int node)
{
    vis[node]=1;
    int i, l=v[node].size();
    for(i=0; i<l; i++)
    {
        if(vis[v[node][i]]==0) dfs(v[node][i]);
    }
}
int main()
{
    int i, t,cs=1;
    scanf("%d", &t);
    while(t--)
    {
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        memset(v, 0, sizeof(v));
        i=0;
        scanf("%d %d %d", &n, &e, &d);

        i=0;
        while(e--)
        {
            int x,y,z;
            scanf("%d %d %d", &x, &y, &z);
            arr[i].a=x;
            arr[i].b=y;
            arr[i].w=z;
            i++;
        }
        e=i;
        sort(arr, arr+i, cmp);
        miNst();
        for(i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                dfs(i);
                ans++;
            }
        }
        printf("Case %d: %d %d\n",cs++, cost+(ans*d), ans);

    }

}
