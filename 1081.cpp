#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 600
ll seg[sz][4*sz];
ll mat[505][505];
ll build(int row, int s, int e, int i)
{
    if(s==e)
    {
        return seg[row][i]= mat[row][s];

    }
    int mid= (s+e)/2;
    return seg[row][i] = max(build(row, s, mid, i*2+1), build(row, mid+1, e, i*2+2));

}
ll query(int row, int s, int e, int i, int l, int r)
{
    if(s>e || l>e || r<s) return -1;
    if(l<=s && r>=e) {
            return seg[row][i];
    }

    int mid= (s+e)/2;
    return max(query(row, s, mid, i*2+1, l, r), query(row, mid+1, e, i*2+2, l, r));
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        memset(seg, 0, sizeof(seg));
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
            build(i, 0, n-1, 0);
        }
        printf("Case %d:\n", cs++);
        while(q--)
        {
            int l,r,x,y,s;
            ll ans=-1;
            scanf("%d %d %d", &x, &y, &s);
            x--;
            y--;

            for(int i=x; i<=x+s-1; i++)
            {

                ans= max(ans, query(i, 0, n-1, 0, y, y+s-1));

            }
            printf("%lld\n", ans);
        }
    }
}
