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
    int t, cs=1, i, j, k, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        j=1;
        string s1, s2;
        int ww;
        map<string, int>mp;
        k=0;

        memset(vis, 0, sizeof(vis));
        memset(v, 0, sizeof(v));
        for(i=0; i<n; i++)
        {
            cin>>s1>>s2>>ww;
            if(mp[s1]==0)
            {
                mp[s1]=j++;
            }
            if(mp[s2]==0)
            {
                mp[s2]=j++;
            }
            v[mp[s1]].push_back(mp[s2]);
            v[mp[s2]].push_back(mp[s1]);
            arr[k].a=mp[s1];
            arr[k].b=mp[s2];
            arr[k].w=ww;
            k++;
        }
        n=j;
        sort(arr, arr+k, cmp);
        printf("Case %d: ", cs++);
        dfs(1);
        bool flag=1;
        for(i=1; i<n; i++)
        {
            if(vis[i]==0)
            {
                flag=0;
                break;
            }
        }
        if(flag) cout<<miNst(k, n)<<endl;
        else cout<<"Impossible"<<endl;
    }
}
