#include<bits/stdc++.h>
using namespace std;
vector<int>v[1100];
bool vis[1100];
void dfs(int n)
{
    vis[n]=1;
    int i, l=v[n].size();
    for(i=0; i<l; i++)
    {
        if(vis[v[n][i]]==0) dfs(v[n][i]);
    }
}
struct st
{
    int a, b, w;

};
st arr[105000];
bool cmp(st aa, st bb)
{
    return aa.w<bb.w;
}
int parent[110];
int find_parent(int n)
{
    if(parent[n]==n) return n;
    return find_parent(parent[n]);
}
void setUnion(int u, int v)
{
    u= find_parent(u);
    v= find_parent(v);

    if(u!=v)
    parent[v]=u;
}
int miNst(int e, int n)
{
    int i, cost=0;

    for(i=0; i<=n; i++) parent[i]=i;
    for(i=0; i<e; i++)
    {
        if(find_parent(arr[i].a)!=find_parent(arr[i].b))
        {
            cost+=arr[i].w;
            setUnion(arr[i].a, arr[i].b);
        }
    }
    return cost;
}
int main()
{

    int i, t,cs=1, x, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(v, 0, sizeof(v));
        int sum=0,j;
        int  k=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cin>>x;
                sum+=x;
                if(x>0)
                {
                    v[i].push_back(j);
                   v[j].push_back(i);
                    arr[k].a=i;
                    arr[k].b=j;
                    arr[k].w=x;
                    k++;
                }
            }
        }

        memset(vis, 0, sizeof(vis));
        dfs(1);
        bool flag=1;
        for(i=1; i<=n; i++)
        if(vis[i]==0)
        {
            flag=0;
            break;
        }
        printf("Case %d: ", cs++);
        if(flag==0)
        {
            cout<<-1<<endl;
            continue;
        }
        sort(arr, arr+k, cmp);
        int ans= sum-miNst(k, n);

        cout<<ans<<endl;
    }
}
