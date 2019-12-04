#include<bits/stdc++.h>
using namespace std;
int move_x[]= {+1, +1, +2, +2, -1, -1, -2, -2};
int move_y[]= {+2, -2, +1, -1, +2, -2, +1, -1};
bool vis[20][20];
map<pair<int, int>, int >mp;
int r, c;
int cont[101][12][12];
bool check(int x, int y)
{
    if(x<=0 || x>r || y<=0 || y>c) return false;
    return true;
}
void bfs(int x, int y, int k, int n)
{
    queue<int>q;
    q.push(x);
    q.push(y);
    memset(vis, 0, sizeof(vis));
    while(q.size())
    {
        x= q.front();
        q.pop();
        y= q.front();
        q.pop();
        vis[x][y]=1;
        mp[make_pair(x, y)]++;

        for(int i=0; i<8; i++)
        {
            int rx= x + move_x[i] ;
            int ry=  y + move_y[i] ;
            if(check(rx, ry) && !vis[rx][ry])
            {
                vis[rx][ry]=1;
                cont[n][rx][ry]= cont[n][x][y]+1;
                q.push(rx);
                q.push(ry);
            }


        }
    }
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            int x=0;
            if(cont[n][i][j]%k!=0)x=1;
            cont[n][i][j]=(cont[n][i][j]/k)+x;
        }
    }

}
int main()
{
    int i,kase=1, t, k, j, n;
    char ch;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        n=0;
        memset(cont, 0, sizeof(cont));
        mp.clear();

        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                cin>>ch;
                if(ch!='.')
                {
                    n++;
                    k= ch-'0';
                    bfs(i, j, k, n);
                }
            }
        }
        int sum=0, ans= INT_MAX;
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                if(mp[make_pair(i, j)]==n)
                {
                    sum=0;
                    for(int l=1; l<=n; l++)
                    {
                        sum+=cont[l][i][j];
                    }
                    ans= min(ans, sum);
                }
            }
        }
        if(ans==INT_MAX) ans=-1;
        cout<<"Case "<<kase++<<": "<< ans<<endl;
    }
    return 0;
}
