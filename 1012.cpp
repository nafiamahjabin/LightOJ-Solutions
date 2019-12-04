#include<bits/stdc++.h>
using namespace std;
char s[50][50];
int move_x[] = {0,0,-1,+1};
int move_y[] ={-1,+1,0,0}, r, c;
bool vis[100][100];
bool check(int x, int y)
{
    if(x<=0 || y<=0 || x>r || y>c || s[x][y]=='#') return false;
    return true;
}
int bfs(int x, int y)
{
    int cont=0;
    queue<int>q;
    q.push(x);
    q.push(y);
    while(q.size())
    {
        cont++;
        x= q.front();
        q.pop();
        y= q.front();
        q.pop();
        vis[x][y]=1;
        for(int i=0; i<4; i++)
        {
            int rx= x+move_x[i];
            int ry = y+move_y[i];

            if(check(rx,ry) && !vis[rx][ry])
            {
                q.push(rx);
                q.push(ry);
                vis[rx][ry]=1;
            }
        }

    }
    return cont;

}
int main()
{
    int i,j, x,y,t, kase=1;
    char  ch;
    cin>>t;
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        cin>>c>>r;
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                cin>>ch;
                if(ch=='@') x=i, y=j;
                s[i][j]=ch;
            }
            s[i][j]='\0';
        }
        cout<<"Case "<<kase++<<": "<<bfs(x, y)<<endl;
    }
    return 0;
}

