#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 200200
ll seg[sz*4];
ll lazy[sz*4];
ll arr[sz];
struct st
{
    ll l,r;
} q[sz];
void build(ll s, ll e, ll i)
{
    if(s==e)
    {
        seg[i]=arr[s];
        return;
    }
    ll mid=(s+e)/2;
    build(s, mid,i*2+1);
    build(mid+1, e,i*2+2);
    seg[i]=max(seg[i*2+1], seg[i*2+2]);
}
void update(ll s, ll e, ll l,ll r, ll i)
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
        seg[i]=0;
        if(s!=e)
        {
            lazy[i*2+1]=0;
            lazy[i*2+2]=0;
        }
        return ;
    }
    ll mid= (s+e)/2;
    update(s, mid, l, r,  i*2+1);
    update(mid+1, e, l, r,i*2+2);
    seg[i]= max(seg[i*2+1],seg[i*2+2]);


}
ll query( ll s, ll e, ll l, ll r, ll i)
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
    return max(query(s, mid, l, r, i*2+1),query(mid+1, e, l, r, i*2+2));

}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        memset(arr,0,sizeof(arr));
        memset(seg,0,sizeof(seg));
        memset(lazy,-1,sizeof(lazy));
        scanf("%lld", &n);
        ll nn=n;
        for(int i=0; i<n; i++)
        {
            scanf("%lld %lld", &q[i].l, &q[i].r);
            q[i].l--;
            q[i].r--;
            arr[q[i].l]++;
            arr[q[i].r+1]--;
        }
        n*=2;
        for(int i=1; i<n; i++)
            arr[i]+=arr[i-1];

        build(0,n-1, 0);

        ll cnt=0;
        for(int i=nn-1; i>=0; i--)
        {
            ll v = query(0,n-1,q[i].l,q[i].r, 0);
            if(v!=0)
            {
                cnt++;
                update(0,n-1,q[i].l, q[i].r,0);
            }
        }
        printf("Case %d: %lld\n",cs++,cnt);


    }
}
