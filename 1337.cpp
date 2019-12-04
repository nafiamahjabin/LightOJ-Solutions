#include<bits/stdc++.h>
using namespace std;
int vis[505][505], cnt[505][505];
int n,m, ans;
int dx[]={-1, 0, +1, 0};
int dy[]={0, +1, 0, -1};
string s[505];
bool check(int rx, int ry)
{
    if(rx>=0 && rx<n && ry>=0 && ry<m)
    {
        if(s[rx][ry]=='#') return false;
        else return true;
    }
    return false;
}
void bfs(int x, int y)
{
    if(cnt[x][y]!=0) return;
    memset(vis, 0, sizeof(vis));
    ans=0;
    vector<int>v;
    queue<int>q;
    q.push(x);
    q.push(y);
    v.push_back(x);
    v.push_back(y);
    while(q.size())
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        if(s[x][y]=='C') ans++;
        vis[x][y]=1;
        for(int i=0; i<4; i++)
        {
            int rx=x+dx[i];
            int ry=y+dy[i];
            if(check(rx, ry) && vis[rx][ry]==0)
            {
                q.push(rx);
                q.push(ry);
                v.push_back(rx);
                v.push_back(ry);
                vis[rx][ry]=1;

            }
        }
    }
    int l=v.size();
    for(int i=0; i<l; i+=2)
    {
        cnt[v[i]][v[i+1]]=ans;
    }
}
int main()
{
    int q, i, j, t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        for(i=0; i<n; i++)
        {
            cin>>s[i];

        }
        printf("Case %d:\n", cs++);
        memset(cnt, 0, sizeof(cnt));
        while(q--)
        {
            int a, b;
            cin>>a>>b;

            bfs(a-1, b-1);
            printf("%d\n",cnt[a-1][b-1]);
        }
    }
}
