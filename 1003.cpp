#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
bool visited[10000];
map<string, int>mp;
bool check;
int root;
void dfs(int n)
{
    visited[n]=1;
    int l= v[n].size();
    int i;
    for(i=0; i<l; i++)
    {
        if(root==v[n][i])
        {
            check=false;
            return ;
        }
        else if(visited[v[n][i]]==0)
        {
            dfs(v[n][i]);
        }
    }
}
int main()
{
    int t, j, kase=1, n;
    string s[10000];
    scanf("%d", &t);
    while(t--)
    {
        memset(v, 0, sizeof(v));
        string a, b;
        scanf("%d", &n);
        int i;
        mp.clear();
        for(i=0, j=0; i<n; i++)
        {
            cin >> a>> b;
            if(mp[a]==0)
            {
                mp[a]=++j;
            }
            if(mp[b]==0)
            {
                mp[b]=++j;
            }

            v[mp[a]].push_back(mp[b]);
        }
        check=true;
        for(i=1; i<=j; i++)
        {
            memset(visited, 0, sizeof(visited));
            if(visited[i]==0)
            {
                root=i;
                dfs(i);
            }
            if(!check)
            {
                break;
            }
        }
        if(check)
        {
            printf("Case %d: Yes\n", kase++);
        }
        else
        {
            printf("Case %d: No\n", kase++);
        }
    }
    return 0;
}
