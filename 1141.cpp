#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool mark[110], vis[10000];
int p[110], cnt[10000];
vector<int>prime[11000];
void sieve()
{
    int i, j, n=10007;
    for(i=2; i*i<=n; i++)
    {
        if(mark[i]==0)
        {
            for(j=i+i; j<=n; j+=i) mark[j]=1;
        }
    }
    j=0;
    for(i=2; i<=1000; i++) if(mark[i]==0) p[j++]=i;
    for(i=2; i<=1000; i++)
    {
        for(int k=0; k<j && p[k]<i; k++)
        {
            if(i%p[k]==0) prime[i].push_back(p[k]);
        }
    }
}
void bfs(int s, int n)
{
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    queue<int>q;
    q.push(s);
    int xx=s;
    while(q.size())
    {
        s= q.front();
        q.pop();
        vis[s]=1;
        if(s==n) break;
        int l= prime[s].size();
        for(int i=0; i<l; i++)
        {
            int x= s+prime[s][i];
            if(vis[x]==0 && x<=n)
            {
                q.push(x);
                vis[x]=1;
                cnt[x]=cnt[s]+1;
            }
        }
    }
}
int main()
{
    sieve();
    int s, t, cs=1, n;
    cin>>t;
    while(t--)
    {
        cin>>s>>n;

        bfs(s, n);
        if(cnt[n]==0 && s!=n) cnt[n]=-1;
        printf("Case %d: %d\n", cs++, cnt[n]);
    }
}
