#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        ll n, ans;
        cin>>n;
        ans=sqrt(n);
        ans+=(sqrt(n/2));
        printf("Case %d: %lld\n", cs++, n-ans);
    }
}
