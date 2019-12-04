#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll t, n,cs=1,q, arr[100006], i, j;
    scanf("%lld", &t);
    while(t--)
    {
        cin>>n>>q;
        arr[0]=-1;

        for(i=0; i<n; i++)
        {
            scanf("%lld", &arr[i]);

        }
        printf("Case %lld:\n", cs++);
        while(q--)
        {
            scanf("%lld %lld",&i, &j);
            ll beg= lower_bound(arr, arr+n, i)-arr;
            ll end= upper_bound(arr, arr+n, j)-arr;
            printf("%lld\n", end-beg);

        }
    }
}
