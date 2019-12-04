#include<bits/stdc++.h>
using namespace std;
int tk[1005], sum, cont;
vector<int>v[1005];
bool vis[1005];
void dfs(int n)
{
    cont++;
    sum+=tk[n];
    vis[n]=1;
    int l= v[n].size(), i;
    for(i=0; i<l; i++)
    {
        if(!vis[v[n][i]]) dfs(v[n][i]);
    }
}
int main()
{
    int n,m , i,kase=1,avg, t, a, b;
    scanf("%d", &t);
    while(t--)
    {
        memset(v, 0, sizeof(v));
        memset(vis, 0, sizeof(vis));
        sum=0;
        scanf("%d %d", &n, &m);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&tk[i]);
            sum+=tk[i];
        }
        int ok=1;
        if(sum%n==0) avg= sum/n;
        else
        {
            ok=0;
        }

        while(m--)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(ok==1)
        {
            for(i=1; i<=n; i++)
            {
                if(!vis[i])
                {
                    cont=0;
                    sum=0;
                    dfs(i);
                    if(sum%cont==0)
                    {
                     if(sum/cont!=avg){
                        ok=0;
                        break;
                     }
                    }
                    else
                    {
                        ok=0;
                        break;
                    }
                }
            }
            if(ok) printf("Case %d: Yes\n", kase++);
            else printf("Case %d: No\n", kase++);
        }
        else printf("Case %d: No\n", kase++);
    }
    return 0;
}
