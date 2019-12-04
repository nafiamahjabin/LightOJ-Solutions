#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int  arr[mx];
int minseg[4*mx];
int maxseg[4*mx];
int buildmax(int s, int e, int i)
{
    if(s==e)
    {
        return maxseg[i]=arr[s];

    }
    int mid = (s+e)/2;
    return maxseg[i]= max(buildmax(s, mid, i*2+1), buildmax(mid+1, e, i*2+2));

}
int buildmin(int s, int e, int i)
{
    if(s==e)
    {
        return minseg[i]= arr[s];

    }
    int mid = (s+e)/2;
    return minseg[i]= min(buildmin(s, mid, i*2+1), buildmin(mid+1, e, i*2+2));

}
int getmax(int s, int e,int i, int l, int r)
{
    if(s>e || l>e || r<s)
        return 0;
    else if(l<=s && r>=e)
        return maxseg[i];
    int mid = (s+e)/2;
    return max(getmax(s, mid,i*2+1, l, r), getmax(mid+1,e, i*2+2, l, r));

}
int getmin(int s, int e,int i, int l, int r)
{
    if(s>e || l>e || r<s)
        return INT_MAX;
    else if(l<=s && r>=e)
        return minseg[i];
    int mid = (s+e)/2;
    return min(getmin(s, mid,i*2+1, l, r), getmin(mid+1,e, i*2+2, l, r));

}
int main()
{
    int i, j,kase=1,d, t, ans, n;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        for(i=1; i<=n; i++)
            cin>>arr[i];
        buildmax(1, n, 1);
        buildmin(1, n, 1);
        ans= getmax(1, n,1, 1, d)-getmin(1, n,1, 1, d);
        for(i=d+1; i<=n; i++)
        {
            ans = max(ans, (getmax(1, n,1, i-d+1, i)-getmin(1, n,1, i-d+1, i)));
        }
        cout<<"Case "<<kase++<<": "<<ans<<endl;
    }
}
