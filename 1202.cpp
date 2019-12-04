#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x1,y1,x2,y2, t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        printf("Case %d: ", cs++);
        if(((x1+y1)%2)!=((x2+y2)%2)) cout<<"impossible\n";
        else if(abs(x1-x2)==abs(y1-y2)) cout<<1<<endl;
        else cout<<2<<endl;
    }
}
