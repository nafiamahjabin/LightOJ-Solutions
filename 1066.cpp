#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct ind
{
    int i, j;
    char c;

};
ind ar[15];
bool cmp(ind a, ind b)
{
    return a.c<b.c;
}
map<char, pair<int, int> >mp;
int dx[]={0,0,+1,-1};
int dy[]={+1,-1,0,0};
bool vis[15][15];
int cnt[15][15], n;
string s[15];
bool check(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=n || s[x][y]=='#') return false;
    else return true;

}
void bfs(int x, int y, int xx, int yy)
{
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    queue<int>q;

    q.push(x);q.push(y);
    while(q.size())
    {
        x= q.front();
        q.pop();
        y= q.front();
        q.pop();
        vis[x][y]=1;
        if(x==xx && y==yy) return ;

        for(int i=0; i<4; i++)
        {
            int rx=x+dx[i];
            int ry=y+dy[i];
            if(check(rx,ry) && vis[rx][ry]==0)
            {
                cnt[rx][ry]=cnt[x][y]+1;
                q.push(rx);
                q.push(ry);
                vis[rx][ry]=1;
            }
        }

    }
}
int main()
{
    FastRead;
    int t, cs=1,k,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;

        for(i=0; i<n; i++){
             cin>>s[i];
        }

        for(i=0, k=0; i<n; i++)
        {
            for(j=0; j<n;j++)
            {
                if(s[i][j]>='A' && s[i][j]<='Z')
                {
                    mp[s[i][j]]=make_pair(i,j);
                    ar[k].i=i;ar[k].j=j;
                    ar[k].c=s[i][j];
                    k++;
                }

            }
        }
        sort(ar, ar+k,cmp);

        int sum=0;
        bool flag=true;
        for(i=0; i<k-1; i++)
        {
            int srcX=ar[i].i;
            int srcY=ar[i].j;
            int desX=ar[i+1].i;
            int desY=ar[i+1].j;
            for(j=0; j<k; j++)
            {
                if(j<=i+1)
                {
                    s[ar[j].i][ar[j].j]=ar[j].c;
                }
                else s[ar[j].i][ar[j].j]='#';

            }
            bfs(srcX, srcY, desX, desY);
            if(vis[desX][desY]==0)
            {
                flag=false;
                break;
            }
            sum+=cnt[desX][desY];
        }
        if(flag) cout<<"Case "<<cs++<<": "<<sum<<endl;
        else cout<<"Case "<<cs++<<": "<<"Impossible"<<endl;



    }
}
