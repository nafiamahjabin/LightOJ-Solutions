#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 20
int dx[]= {0,0,+1,-1};
int dy[]= {+1,-1, 0,0};
int vis[11][11][11][11][11][11],cnt[11][11][11][11][11][11];
int des[sz][sz], ok[5];
string s[sz];
int n, x1,yy1,x2,y2,x3,y3, ans;
bool check(int a1,int b1)
{
    if(a1>=0 && a1<n && b1>=0&& b1<n )
    {
        if(s[a1][b1]=='#')
            return false;

        return true;
    }
    return false;
}
bool checkPoint(int a1, int b1, int a2, int b2)
{
    if(a1==a2 && b1==b2) return false;
    return true;
}

int bfs()
{
    queue<int>q;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    q.push(x1);
    q.push(yy1);
    q.push(x2);
    q.push(y2);
    q.push(x3);
    q.push(y3);

    while(q.size())
    {
        x1=q.front();
        q.pop();
        yy1=q.front();
        q.pop();
        x2=q.front();
        q.pop();
        y2=q.front();
        q.pop();
        x3=q.front();
        q.pop();
        y3=q.front();
        q.pop();
        if(des[x1][yy1] && des[x2][y2] && des[x3][y3]){
            return cnt[x1][yy1][x2][y2][x3][y3];
        }
        vis[x1][yy1][x2][y2][x3][y3]=1;
        for(int i=0; i<4; i++)
        {
            int rx1=x1, rx2=x2, rx3=x3, ry1=yy1, ry2=y2, ry3=y3;
            if(check(rx1+dx[i],ry1+dy[i]) )
            {
                rx1+=dx[i];
                ry1+=dy[i];
            }
            if(check(rx2+dx[i],ry2+dy[i]))
            {
                rx2+=dx[i];
                ry2+=dy[i];
            }
            if(check(rx3+dx[i],ry3+dy[i]))
            {
                rx3+=dx[i];
                ry3+=dy[i];
            }
            if((!checkPoint(rx1,ry1,x2,y2) && !checkPoint(x2,y2,rx2,ry2)) ||(!checkPoint(rx1,ry1,x3,y3) && !checkPoint(x3,y3,rx3,ry3)))
            {
                rx1=x1;
                ry1=yy1;
            }
            if((!checkPoint(rx2,ry2,x1,yy1) && !checkPoint(x1,yy1,rx1,ry1)) ||(!checkPoint(rx2,ry2,x3,y3) && !checkPoint(x3,y3,rx3,ry3)))
            {
                rx2=x2;
                ry2=y2;
            }
            if((!checkPoint(rx3,ry3,x2,y2) && !checkPoint(x2,y2,rx2,ry2)) ||(!checkPoint(rx3,ry3,x1,yy1) && !checkPoint(x1,yy1,rx1,ry1)))
            {
                rx3=x3;
                ry3=y3;
            }
            if((!checkPoint(rx1,ry1,x2,y2) && !checkPoint(x2,y2,rx2,ry2)) ||(!checkPoint(rx1,ry1,x3,y3) && !checkPoint(x3,y3,rx3,ry3)))
            {
                rx1=x1;
                ry1=yy1;
            }
            if((!checkPoint(rx2,ry2,x1,yy1) && !checkPoint(x1,yy1,rx1,ry1)) ||(!checkPoint(rx2,ry2,x3,y3) && !checkPoint(x3,y3,rx3,ry3)))
            {
                rx2=x2;
                ry2=y2;
            }
            if((!checkPoint(rx3,ry3,x2,y2) && !checkPoint(x2,y2,rx2,ry2)) ||(!checkPoint(rx3,ry3,x1,yy1) && !checkPoint(x1,yy1,rx1,ry1)))
            {
                rx3=x3;
                ry3=y3;
            }
            if(!vis[rx1][ry1][rx2][ry2][rx3][ry3])
            {
                cnt[rx1][ry1][rx2][ry2][rx3][ry3]= cnt[x1][yy1][x2][y2][x3][y3]+1;
                q.push(rx1);
                q.push(ry1);
                q.push(rx2);
                q.push(ry2);
                q.push(rx3);
                q.push(ry3);

                vis[rx1][ry1][rx2][ry2][rx3][ry3]=1;

            }



        }

    }
    return -1;
}
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        memset(des, 0, sizeof(des));
        memset(ok, 0, sizeof(ok));

        cin>>n;
        for(int i=0; i<n; i++)
            cin>>s[i];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i][j]=='A')
                {
                    x1=i;
                    yy1=j;
                    ok[1]=0;
                }
                if(s[i][j]=='B')
                {
                    x2=i;
                    y2=j;
                    ok[2]=0;
                }
                if(s[i][j]=='C')
                {
                    x3=i;
                    y3=j;
                    ok[2]=0;
                }
                if(s[i][j]=='X')
                {
                    des[i][j]=1;
                }
            }
        }
        ans= bfs();
        cout<<"Case "<<cs++<<": ";
        if(ans==-1) cout<<"trapped"<<endl;
        else cout<<ans<<endl;
    }
}
