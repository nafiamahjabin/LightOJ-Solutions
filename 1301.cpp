#include<bits/stdc++.h>
using namespace std;
#define sz 101000
struct st
{
    int s, e;
}arr[sz];
bool cmp(st a, st b)
{
    return a.e<b.e;
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        vector<int>v;
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &arr[i].s, &arr[i].e);
        sort(arr,arr+n,cmp);

        int cnt=1;
        v.push_back(arr[0].e);
        for(int i=1; i<n; i++)
        {

            int x= arr[i].s;
            int in = lower_bound(v.begin(), v.end(),x)-v.begin();

            if(in==0)
            {
                v.push_back(arr[i].e);
                cnt++;
            }
            else if(v[in-1]>=x)
            {
                cnt++;
                v.push_back(arr[i].e);
            }
            else
            {
                x=v[in-1];
                auto it= lower_bound(v.begin(), v.end(),x);
                v.erase(it);

                v.push_back(arr[i].e);
            }
        }
       printf("Case %d: %d\n", cs++,cnt);
    }
}
