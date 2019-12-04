#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m,w, p, t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>w;
        p=1;
        bool ok=0;
        for(ll i=0; p<w; i++)
        {
            if(i<63)
            p*=2;
            else break;
            if(w%p==0)
            {
                if((ll)(w/p)%2==1)
                {
                    n=w/p;m=p;
                    ok=1;
                    break;
                }
            }
        }
        printf("Case %lld: ", cs++);
        if(ok) cout<<n<<" "<<m<<endl;
        else cout<<"Impossible"<<endl;
    }
}
