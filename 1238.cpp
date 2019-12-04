#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,+1,0};
int dy[]={0, +1,0,-1};
int cnt[100][100],n,m, d1, d2;
bool vis[100][100];
string s[110];
bool check(int rx, int ry)
{
    if(rx>=0 && rx<n && ry>=0 && ry<m)
    {
        if(s[rx][ry]=='m' ||  s[rx][ry]=='#') return false;
        else return true;
    }
    return false;
}
void bfs(int x, int y)
{
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    queue<int>q;
    q.push(x);
    q.push(y);
    while(q.size())
    {
        x= q.front();
        q.pop();
        y=q.front();
        q.pop();
        vis[x][y]=1;
        if(x==d1 && y==d2) break;
        for(int i=0; i<4; i++)
        {
            int rx= x+dx[i];
            int ry= y+dy[i];
            if(check(rx,ry) && vis[rx][ry]==0)
            {
                q.push(rx);
                q.push(ry);
                vis[rx][ry]=1;

                cnt[rx][ry]=cnt[x][y]+1;
            }
        }
    }
}
int main()
{
    int i, j, t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            cin>>s[i];
        }
        int a1,a2,b1,b2,c1,c2;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='a')
                {
                    a1=i;
                    a2=j;
                }
                else if(s[i][j]=='b')
                {
                    b1=i;
                    b2=j;
                }
                else if(s[i][j]=='c')
                {
                    c1=i;
                    c2=j;
                }
                else if(s[i][j]=='h')
                {
                    d1=i;
                    d2=j;
                }
            }
        }
        bfs(a1, a2);
        int ans= cnt[d1][d2];
        bfs(b1, b2);
        ans=max(ans, cnt[d1][d2]);
        bfs(c1, c2);
        ans=max(ans, cnt[d1][d2]);
        printf("Case %d: %d\n", cs++, ans);
    }
}
