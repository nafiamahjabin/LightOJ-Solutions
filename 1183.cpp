#include<bits/stdc++.h>
using namespace std;
#define mx 100010
#define ll long long
ll arr[mx];
ll seg[mx*4];
ll lazy[mx*4];
void build(ll s, ll e, ll i)
{
    if(s==e)
    {
        seg[i]=arr[s];
        return;
    }
    ll mid=(s+e)/2;
    build(s, mid, i*2+1);
    build(mid+1, e, i*2+2);
    seg[i]=seg[i*2+1]+seg[i*2+2];
}
void first_queryLazy(ll s, ll e, ll l, ll r,ll v, ll i)
{
    if(s>e) return ;
    if(lazy[i]!=-1)
    {
        seg[i]=(e-s+1)*lazy[i];
        if(s!=e)
        {
            lazy[i*2+1]=lazy[i];
            lazy[i*2+2]=lazy[i];
        }
        lazy[i]=-1;
    }
    if(l>e || r<s) return ;

    if(l<=s && r>=e)
    {
        seg[i]=(e-s+1)*v;
        if(s!=e)
        {
            lazy[i*2+1]=v;
            lazy[i*2+2]=v;
        }
        return ;
    }
    ll mid= (s+e)/2;
    first_queryLazy(s, mid, l, r, v, i*2+1);
    first_queryLazy(mid+1, e, l, r, v, i*2+2);
    seg[i]= seg[i*2+1]+seg[i*2+2];

}
ll second_query( ll s, ll e, ll l, ll r, ll i)
{
    if(s>e) return 0;
    if(lazy[i]!=-1)
    {

        seg[i]=(e-s+1)*lazy[i];
        if(s!=e)
        {
            lazy[i*2+1]=lazy[i];
            lazy[i*2+2]=lazy[i];
        }
        lazy[i]=-1;
    }
    if(l>e || r<s) return 0;
    else if(l<=s && r>=e) return seg[i];
    ll mid= (s+e)/2;
    return second_query(s, mid, l, r, i*2+1)+second_query(mid+1, e, l, r, i*2+2);

}
int main()
{
    ll t, n, q,cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        memset(lazy,-1,sizeof(lazy));
        memset(seg,0,sizeof(seg));
        memset(arr,0,sizeof(arr));
        scanf("%lld %lld", &n, &q);
        build(0,n-1,0);
        printf("Case %lld:\n", cs++);
        while(q--)
        {
            ll type, l, r, v;
            scanf("%lld", &type);
            if(type==1)
            {
                scanf("%lld %lld %lld", &l, &r, &v);
                first_queryLazy(0,n-1, l,r,v,0);
            }
            else
            {
                scanf("%lld %lld", &l, &r);
                ll sum=second_query(0,n-1,l,r,0);
                ll num = r-l+1;
                ll avg=sum/num;
                if(avg*num==sum)
                {
                    printf("%lld\n", avg);
                }
                else
                {
                    printf("%lld/%lld\n",sum/__gcd(sum,num),num/__gcd(sum,num));
                }
            }
        }
    }
}

