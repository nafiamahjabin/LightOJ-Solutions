#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000000000+7
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll b=131;
ll pw[1000006];
ll hashV[1000006];
ll hashV2[1000006];

void gnrtPow()
{
    pw[0]=1;
    for(int i=1; i<=1000006; i++)
    {
        pw[i]=(pw[i-1]*b);
    }
}
void hash_val(string str)
{
    ll len=str.size();
    hashV[0]=0;
    for(ll i=1; i<len; i++)
    {
        hashV[i]= ((hashV[i-1]*b)+str[i]);
    }
}
void hash_val2(string str)
{
    ll len=str.size();
    hashV2[0]=0;
    for(ll i=1; i<len; i++)
    {
        hashV2[i]= ((hashV2[i-1]*b)+str[i]);
    }
}
ll segHash(int i, int j)
{
    return (hashV[j]-hashV[i-1]*pw[j-i+1]);
}
ll segHash2(int i, int j)
{
    return (hashV2[j]-hashV2[i-1]*pw[j-i+1]);
}

int main()
{
    FastRead;

    int t, cs=1;
    string s;
    cin>>t;
    gnrtPow();
    while(t--)
    {
        cin>>s;
        memset(hashV, 0, sizeof(hashV));
        int i;
        s="*"+s;
        ll l=s.size();
        hash_val(s);
        string s2;
        for(i=l-1; i>=1; i--) s2+=s[i];
        s2="*"+s2;
        hash_val2(s2);
        for(i=1; i<l; i++)
        {
            ll x=segHash(i, l-1);
            ll y=segHash2(1, l-i);
            if(x==y) {
                break;
            }
        }
        cout<<"Case "<<cs++<<": "<<l+i-2<<endl;
    }

}
