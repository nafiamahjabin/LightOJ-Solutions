#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
ll arr[mx];
ll seg[mx*4];
ll lazy[mx*4];
void first_queryLazy(int s, int e, int l, int r,int v, int i)
{
    if(s>e) return ;
    if(lazy[i]!=0)
    {
        seg[i]+=(e-s+1)*lazy[i];
        if(s!=e)
        {
            lazy[i*2+1]+=lazy[i];
            lazy[i*2+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>e || r<s) return ;

    if(l<=s && r>=e)
    {
        seg[i]+=(e-s+1)*v;
        if(s!=e)
        {
            lazy[i*2+1]+=v;
            lazy[i*2+2]+=v;
        }
        return ;
    }
    int mid= (s+e)/2;
    first_queryLazy(s, mid, l, r, v, i*2+1);
    first_queryLazy(mid+1, e, l, r, v, i*2+2);
    seg[i]= seg[i*2+1]+seg[i*2+2];

}
ll second_query(int s, int e, int l, int r, int i)
{
    if(s>e) return 0;
    if(lazy[i]!=0)
    {
        seg[i]+=(e-s+1)*lazy[i];
        if(s!=e)
        {
            lazy[i*2+1]+=lazy[i];
            lazy[i*2+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>e || r<s) return 0;
    else if(l<=s && r>=e) return seg[i];
    int mid= (s+e)/2;
    return second_query(s, mid, l, r, i*2+1)+second_query(mid+1, e, l, r, i*2+2);

}
int main()
{
    int t, x, kase=1;
    scanf("%d", &t);
    while(t--)
    {
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));
        memset(arr, 0, sizeof(arr));
        int n, i, j, l, r,v, q;
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", kase++);
        while(q--)
        {
            scanf("%d %d %d", &x, &l, &r);
            if(x==0)
            {
                scanf("%d", &v);
                first_queryLazy(0, n-1, l, r, v, 0);

            }
            else
            {
                printf("%lld\n", second_query(0, n-1, l, r, 0));
            }
        }
    }

}
