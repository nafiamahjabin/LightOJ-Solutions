#include<bits/stdc++.h>
using namespace std;
#define sz 1000010

struct query
{
    int l, r, no;


}q[sz];
int f[sz], arr[sz], ans[sz],cnt, block;
bool cmp(query a, query b)
{
    int x=a.l/block;
    int y=b.l/block;
    if(x!=y) return x<y;
    else return a.r<b.r;

}
void del(int index)
{
    f[arr[index]]--;
    if(!f[arr[index]]) cnt--;

}
void add(int index)
{
    if(!f[arr[index]])cnt++;
    f[arr[index]]++;
}
int main()
{
    int t,cs=1;
    scanf("%d", &t);
    while(t--)
    {
        int n,i, que;

        memset(f,0,sizeof(f));
        memset(q,0,sizeof(q));
        memset(arr,0,sizeof(arr));
        scanf("%d%d", &n, &que);
        block=1000;
        for(i=1; i<=n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for(i=1; i<=que; i++)
        {
            scanf("%d%d", &q[i].l, &q[i].r);

            q[i].no=i;
        }
        sort(q+1,q+que+1, cmp);
        int s=1;
        int e=0; cnt=0;

        for(i=1; i<=que; i++)
        {
            int x=q[i].l, y=q[i].r;

            while(s<x)
            {
                del(s);
                s++;
            }
            while(s>x)
            {
                s--;
                add(s);

            }
            while(e>y)
            {
                del(e);
                e--;

            }
            while(e<y)
            {
                e++;
                add(e);
            }
            ans[q[i].no]=cnt;

        }
        printf("Case %d:\n", cs++);
        for(i=1; i<=que; i++) printf("%d\n", ans[i]);
    }

}
