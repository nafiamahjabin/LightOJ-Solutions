#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
map<int, int>mp;
int vmp,  lyk, cont[100005];
bool vis[100005];
void bfs(int n)
{
    queue<int>q;
    q.push(n);
    while(!q.empty())
    {
        n= q.front();
        q.pop();
        vis[n]=1;
        if(cont[n]%2==0) vmp++;
        else lyk++;
        int l= v[n].size();
        for(int i=0; i<l; i++)
        {
            if(!vis[v[n][i]])
            {
                cont[v[n][i]]= cont[n]+1;
                vis[v[n][i]]=1;
                q.push(v[n][i]);
            }
        }
    }
}

int main()
{
    int n, e, a, b, t, kase=1, i, ans;
    scanf("%d", &t);
    while(t--)
    {
        n=0;
        ans= 0;

        memset(v, 0, sizeof(v));
        memset(vis, 0, sizeof(vis));
        mp.clear();
        scanf("%d", &e);
        n= -INT_MAX;
        while(e--)
        {
            scanf("%d %d", &a, &b);
            mp[a]=1;
            mp[b]=1;
            v[a].push_back(b);
            v[b].push_back(a);
            n= max(n,max(a,b));
        }
        memset(cont, 0, sizeof(cont));
        for(i=1; i<=n; i++)
        {
            if(mp[i]!=0 && !vis[i])
            {
                vmp=0, lyk=0;
                bfs(i);
                ans+=(max(vmp,lyk));
            }
        }
        printf("Case %d: %d\n", kase++,ans);
    }
    return 0;
}


