#include<bits/stdc++.h>
using namespace std;
#define len 100005
#define ll long long
ll arr[len];
ll seg[len*4];
ll built(ll i, ll s, ll e)
{
    if(s==e) return seg[i]= arr[s];
    ll mid= (s+e)/2;
    return seg[i]= built(i*2+1, s, mid)+ built(i*2+2, mid+1, e);
}
ll query(ll i, ll s, ll e, ll l, ll r)
{
    if(r<s || l>e) return 0;
    else if(l<=s && r>=e) return seg[i];
    int mid= (s+e)/2;
    return query(i*2+1, s, mid, l, r)+query(i*2+2, mid+1, e, l, r);
}
void update(ll i, ll s, ll e,ll in, ll v)
{
    if(s>e || in<s || in>e) return ;
    if(s==e && s==in)
    {
        seg[i]=arr[s];
        return ;
    }
    ll mid= (s+e)/2;
    update(i*2+1, s, mid,in, v);
    update(i*2+2, mid+1, e,in,v);
    seg[i]= (seg[i*2+1]+seg[i*2+2]);

}
int main()
{
    ll n,i, q, t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &q);
        for(i=0; i<n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        built(0, 0, n-1);
        printf("Case %lld:\n", cs++);
        while(q--)
        {
            ll x, l, r;

            scanf("%lld", &x);

            if(x==1)
            {
                scanf("%lld", &l);
                printf("%lld\n", arr[l]);
                arr[l]=0;
                update(0,0, n-1, l, 0);

            }
            else if(x==2)
            {
                scanf("%lld %lld", &l, &r);
                arr[l]+=r;
                update(0,0, n-1, l, r);
            }
            else if(x==3)
            {
                scanf("%lld %lld", &l, &r);
                printf("%lld\n", query(0,0, n-1, l, r));
            }
        }
    }
}
