#include<bits/stdc++.h>
using namespace std;
struct st
{
    int a, b, w;

};
st arr[100005];
bool cmp(st aa, st bb)
{
    return aa.w<bb.w;
}
int parent[1010], n, e;
int find_parent(int n)
{
    if(parent[n]==n) return n;
    return find_parent(parent[n]);
}
void setUnion(int u, int v)
{
    u= find_parent(u);
    v= find_parent(v);

    if(u!=v)
    parent[v]=u;
}
int miNst()
{
    int i, cost=0;

    for(i=0; i<=n; i++) parent[i]=i;
    for(i=0; i<e; i++)
    {
        if(find_parent(arr[i].a)!=find_parent(arr[i].b))
        {
            cost+=arr[i].w;
            setUnion(arr[i].a, arr[i].b);
        }
    }
    return cost;
}
int maXst()
{
    int i, cost=0;

    for(i=0; i<=n; i++) parent[i]=i;
    for(i=e-1; i>=0; i--)
    {
        if(find_parent(arr[i].a)!=find_parent(arr[i].b))
        {
            cost+=arr[i].w;
            setUnion(arr[i].a, arr[i].b);
        }
    }
    return cost;

}
int main()
{

    int i, t,cs=1;
    cin>>t;
    while(t--)
    {
        i=0;
        cin>>n;
        while(cin>>arr[i].a>>arr[i].b>>arr[i].w)
        {
            if(arr[i].a==0 && arr[i].b==0 && arr[i].w==0) break;
            i++;
        }
        e=i;
        sort(arr, arr+i, cmp);
        int minn= miNst();
        int maxx= maXst();
        printf("Case %d: ", cs++);
        if((minn+maxx)%2!=0) printf("%d/2\n", minn+maxx);
        else printf("%d\n", (minn+maxx)/2);
    }
}
