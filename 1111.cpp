#include<bits/stdc++.h>
using namespace std;
vector<int>v[1010];
bool visited[1010];
int cont[1010][1010];
void bfs(int n)
{
    queue<int>q;
    q.push(n);
    while(!(q.empty()))
    {
        n= q.front();
        q.pop();
        visited[n]=1;
        int l=v[n].size();
        for(int i=0; i<l; i++)
        {
            if(!visited[v[n][i]])
            {
                q.push(v[n][i]);
                visited[v[n][i]]=1;
            }
        }
    }
}
int main()
{
    int test, kase=1,i,a[1010],j, n, m, x, y, p;
    scanf("%d", &test);
    while(test--)
    {
        memset(cont, 0, sizeof(cont));
        memset(visited, 0, sizeof(visited));
        memset(v, 0, sizeof(v));
        scanf("%d %d %d", &p, &n, &m);
        for(i=0; i<p; i++)
        {
            scanf("%d", &a[i]);
        }
        int maxx=0;
        while(m--)
        {
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
        }
        for(i=0; i<p; i++)
        {
            memset(visited, 0, sizeof(visited));
            bfs(a[i]);
            for(j=1; j<=n; j++)
            {
                if(visited[j])
                {
                    cont[a[i]][j]++;
                }
            }
        }
        int ans=0;
        for(i=1; i<=n; i++)
        {
            int c=0;
            for(j=0; j<p; j++)
            {
                if(cont[a[j]][i])
                {
                    c++;
                }
            }
            if(c==p)
            {
                ans++;
            }
        }
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}
