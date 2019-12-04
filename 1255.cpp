#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll B=347, M=1000000000+7;

string a, b;
ll hash(string s, ll l)
{
    ll power=1, h=0,i;
    for(i=l-1; i>=0; i--)
    {
        h= h+ (s[i]*power)%M;
        h%=M;
        power=(power*B)%M;
    }
    return h;
}
ll match()
{
    ll cnt=0;
    ll lenT= a.size();
    ll lenP=b.size();
    if(lenT<lenP) return 0;
    ll hT=hash(a, lenP);
    ll hP= hash(b, lenP);
    if(hT==hP) cnt++;
    ll power=1;
    for(ll i=1; i<lenP;i++)
    {
        power= (power*B)%M;
    }
    for(ll i=lenP; i<lenT; i++)
    {

        hT= (hT- (power*a[i-lenP])%M)%M;
        hT= (hT+M)%M;
        hT= (hT*B)%M;
        hT= (hT+a[i])%M;
        if(hT==hP){
            cnt++;

        }
    }
    return cnt;
}
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        a.clear();
        b.clear();
        cin>>a>>b;
        printf("Case %d: ", cs++);
        cout<<match()<<endl;
    }
}
