#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1005
int n, srcX, m,srcY, desX, desY;
int dx[]= {0,0,-1,+1};
int dy[]= {-1,+1,0,0};
int vis[sz][sz];
int cnt1[sz][sz],cnt2[sz][sz];
string s[sz];
bool check(int x, int y)
{
    if((x>=0 && x<n) && (y>=0 && y<m))
    {
        if(s[x][y]=='#') return false;
        return true;
    }
    return false;
}
void bfs1(int x, int y)
{
    queue<int>q;
    memset(vis, 0, sizeof(vis));
    q.push(x);
    q.push(y);
    cnt1[x][y]=0;
    while(q.size())
    {
        int x= q.front();
        q.pop();
        int y=q.front();
        q.pop();
        vis[x][y]=1;
        for(int i=0; i<4; i++)
        {
            int rx= x+dx[i];
            int ry= y+dy[i];
            if(check(rx,ry) && vis[rx][ry]==0)
            {
                cnt1[rx][ry]=min(cnt1[rx][ry],cnt1[x][y]+1);
                q.push(rx);
                q.push(ry);
                vis[rx][ry]=1;
            }
        }
    }
}

vector<pair<int, int> >F;
void bfs2()
{
    queue<int>q;
    memset(vis, 0, sizeof(vis));
    int i, len=F.size();
    for(i=0; i<len; i++)
    {
        int x=F[i].first;
        int y=F[i].second;
        q.push(x);
        q.push(y);
        cnt2[x][y]=0;
    }
    while(q.size())
    {
        int x= q.front();
        q.pop();
        int y=q.front();
        q.pop();
        vis[x][y]=1;
        for(int i=0; i<4; i++)
        {
            int rx= x+dx[i];
            int ry= y+dy[i];
            if(check(rx,ry) && vis[rx][ry]==0)
            {
                cnt2[rx][ry]=min(cnt2[rx][ry],cnt2[x][y]+1);
                q.push(rx);
                q.push(ry);
                vis[rx][ry]=1;
            }
        }
    }
}

int main()
{

    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int i, j;
        F.clear();
        cin>>n>>m;
        for(i=0; i<n+2;i++)
        {
            for(j=0; j<m+2;j++) {
                    cnt1[i][j]=INT_MAX;
                    cnt2[i][j]=INT_MAX;
            }
        }

        for(i=0; i<n; i++)cin>>s[i];

        vector<pair<int, int> >des;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='J')
                {
                    srcX=i;
                    srcY=j;

                }
                else if(s[i][j]=='F')
                {
                    F.push_back(make_pair(i, j));
                }
                if((i==n-1 || i==0 || j==0 || j==m-1) && (s[i][j]=='.' || s[i][j]=='J')) des.push_back(make_pair(i,j));
            }
        }
        bfs1(srcX, srcY);
        int ans=INT_MAX, flg, l=des.size();
        bfs2();

        for(i=0;i<l; i++)
        {
            int x=des[i].first;
            int y=des[i].second;
            if(cnt1[x][y]<cnt2[x][y]) ans=min(ans, cnt1[x][y]);
        }
        cout<<"Case "<<cs++<<": ";
        if(ans==INT_MAX) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans+1<<endl;
    }
}
