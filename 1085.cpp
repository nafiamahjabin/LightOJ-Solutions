#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
#define mod 1000000007
int bit[sz+5],cnt, arr[sz+5],brr[sz+5];
int getNext(int i)
{
    return i+(i & -i);
}
int getParent(int i)
{
    return i - (i & -i);
}
int getSum(int x)
{
    x++;
    int sum=bit[x];
    while(getParent(x)!=0)
    {
        x=getParent(x);
        sum=(sum+bit[x])%mod;
    }
    return sum;
}
void update(int i, int v)
{
    i++;
    bit[i]=(bit[i]+v)%mod;
    while(getNext(i)<=cnt)
    {
        i=getNext(i);
        bit[i]=(bit[i]+v)%mod;
    }
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        memset(bit, 0, sizeof(bit));
        int n,i;
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            brr[i]=arr[i];
        }
        sort(brr, brr+n);
        map<int,int>mp;
        cnt=1;
        for(i=0; i<n; i++)
        {
            if(mp[brr[i]]==0)
            {
                mp[brr[i]]=cnt++;
            }
        }

        ll ans=0;
        for(i=0; i<n; i++)
        {
            int r= getSum(mp[arr[i]]-1)+1;
            ans= (ans+r)%mod;
            update(mp[arr[i]], r);
        }
        printf("Case %d: %lld\n", cs++, ans);
    }
}
