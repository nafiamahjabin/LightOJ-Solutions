#include<bits/stdc++.h>
using namespace std;
#define ll long long
double pre[1000060];
int main()
{
    pre[0]=0;
    for(int i=1; i<=1000000; i++)
    {
        pre[i]=log(i)+pre[i-1];
    }
    int t, cs=1, n, b;
    cin>>t;
    while(t--)
    {
        cin>>n>>b;
        printf("Case %d: %lld\n", cs++, (ll)(pre[n]/log(b))+1);
    }
}
