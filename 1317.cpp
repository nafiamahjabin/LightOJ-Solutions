#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k, t, cs=1;
    cin>>t;
    while(t--)
    {
        double p;
        cin>>n>>m>>k>>p;
        double ans=p*k*n;

        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }
}
