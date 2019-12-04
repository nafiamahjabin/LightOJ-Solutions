#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
ll arr[mx];
ll seg[mx*4];
ll lazy[mx*4];
ll built(ll i, ll s, ll e)
{
    if(s>e) {
        return 0;
    }
    if(s==e) return seg[i]= arr[s];
    ll mid= (s+e)/2;
    return seg[i]= built(i*2+1, s, mid)+ built(i*2+2, mid+1, e);
}
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
    scanf (" %d", &t);
    while(t--)
    {
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));
        memset(arr, 0, sizeof(arr));
        int n=1, i, j, l, r,v, q;
        char s[100005];
        scanf (" %s", s);

        l=strlen(s);
        for(i=0; i<l; i++) {
            arr[n++]=s[i]-'0';
        }

        built(1,1,n);
        scanf(" %d", &q);


        printf("Case %d:\n", kase++);

        while(q--)
        {
            char c;

            scanf (" %c", &c);

            if(c=='I')
            {
                scanf(" %d %d", &l,&r);

                first_queryLazy(1,n,l,r,1,1);
            }
            else
            {
                scanf(" %d", &l);
                int x=second_query(1,n,l,l,1);

                if(s[l-1]=='0')
                {
                    if(x%2==0) printf("0\n");
                    else printf("1\n");
                }
                else
                {
                    printf("%d\n", x%2);
                }

            }
        }
    }

}
