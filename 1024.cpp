#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10005
ll prime[10005];
bool mark[10005];
string ans;
string multiply(string num1, ll num2)
{
    string s;
    ll i, l, j, carry=0;
    l= num1.size();
    for(i=l-1; i>=0; i--)
    {
        ll x= ((num1[i]-'0')*num2)+carry;
        s+=((x%10)+'0');
        carry= x/10;
    }
    while(carry!=0)
    {
        s+=((carry%10)+48);
        carry/=10;
    }

    l= s.size();
    for(i=0, j=l-1; i<l/2; i++,j--) swap(s[i], s[j]);

    return s;
}
void sieve()
{
    ll i, j;
    for(i=2; i*i<=N; i++)
    {
        if(mark[i]==0)
            for( j=i+i; j<=N; j+=i) mark[j]=1;
    }
    for(i=2,j=0; i<=N; i++) if(mark[i]==0) prime[j++]=i;

}
int main()
{
    sieve();
    ll t, cs=1, n, i, j, arr[1010];
    scanf("%lld", &t);
    while(t--)
    {
        map<ll,ll>mp;
        mp.clear();
        scanf("%lld", &n);
        for(i=0; i<n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        ll k=0, p[2000]={0};
        for(i=0; i<n; i++)
        {
            ll x=arr[i];
            for(ll j=0; prime[j]*prime[j]<=x; j++)
            {
                if(x%prime[j]==0)
                {
                    if(mp[prime[j]]==0)
                    p[k++]=prime[j];
                    ll cnt=0;
                    while(x%prime[j]==0)
                    {
                        x/=prime[j];
                        cnt++;
                    }
                    if(cnt>mp[prime[j]]) mp[prime[j]]=cnt;
                }
            }
            if(x>1)
            {
                if(mp[x]==0)
                {
                    p[k++]=x;
                    mp[x]=1;
                }
            }
        }
        ans.clear();
        ans+='1';
        for(i=0; i<k; i++)
        {
            ll num=1;
            for(j=0; j<mp[p[i]]; j++) num*=p[i];

            ans= multiply(ans,num);
        }
        printf("Case %lld: ", cs++);
        cout<<ans<<endl;

    }

}
