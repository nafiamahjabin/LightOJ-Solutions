#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,cs=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        cout<<"Case "<<cs++<<": "<<(n/2)*m<<endl;
    }
}
