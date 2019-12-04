#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dx[]={+1,0,0,-1,0,0};
int dy[]={0,+1,0,0,-1,0};
int dz[]={0,0,+1,0,0,-1};

bool vis[30][30][30];
ll cont[30][30][30];
bool block[30][30][30];
char start[5], finish[5];

char shift(char c, int x)
{
    if(x==0) return c;
    if(x==1)
    {
        if(c=='z') return 'a';
        else return (char)c+1;
    }
    if(x==-1)
    {
        if(c=='a') return 'z';
        else return (char)c-1;
    }
}
void bfs()
{
    memset(vis, 0, sizeof(vis));
    memset(cont, 0, sizeof(cont));

    queue<char>q;

    q.push(start[0]);
    q.push(start[1]);
    q.push(start[2]);

    while(q.size())
    {
        char a=q.front();
        int x=a-'a';
        q.pop();

        char b=q.front();
        int y=b-'a';
        q.pop();

        char c=q.front();
        int z=c-'a';
        q.pop();

        vis[x][y][z]=1;

        if(a==finish[0] && b==finish[1] && c==finish[2]) break;

        for(int i=0; i<6; i++)
        {
            char aa=shift(a,dx[i]);
            char bb=shift(b,dy[i]);
            char cc=shift(c,dz[i]);


            int xx= aa-'a';
            int yy= bb-'a';
            int zz= cc-'a';

            if(block[xx][yy][zz]!=1 && vis[xx][yy][zz]==0)
            {
                cont[xx][yy][zz]=cont[x][y][z]+1;

                q.push(aa);
                q.push(bb);
                q.push(cc);

                vis[xx][yy][zz]=1;
            }
        }
    }
}
void callForBlock(char a[], char b[], char c[])
{
    int lenA=strlen(a);
    int lenB=strlen(b);
    int lenC=strlen(c), i, j, k;
    for(i=0; i<lenA; i++)
    {
        for(j=0; j<lenB; j++)
        {
            for(k=0; k<lenC; k++)
            {
                int x=a[i]-'a';
                int y=b[j]-'a';
                int z=c[k]-'a';

                block[x][y][z]=1;
            }
        }
    }
}
int main()
{
    ll t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll n;

        memset(block, 0,sizeof(block));

        scanf("%s %s", start, finish);

        char a[30],b[30],c[30];

        scanf("%lld", &n);

        while(n--)
        {
            scanf("%s %s %s",a,b,c);
            callForBlock(a,b,c);
        }

        printf("Case %lld: ", cs++);

        int xs=start[0]-'a', ys=start[1]-'a', zs=start[2]-'a';
        int xf=finish[0]-'a', yf=finish[1]-'a', zf=finish[2]-'a';

        if(block[xs][ys][zs]==1 || block[xf][yf][zf]==1) {
                printf("-1\n");
                continue;
        }


        bfs();


        if(vis[xf][yf][zf]==0) printf("-1\n");

        else printf("%lld\n", cont[xf][yf][zf]);

    }
}

