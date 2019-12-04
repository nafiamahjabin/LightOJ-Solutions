#include<bits/stdc++.h>
using namespace std;
#define M 2147483647
#define m 100005
#define ld long long int
bool arr[m];
int dp[m], n;
vector<int>prime;
bitset<m>mark;
void sieve()
{
    n= sqrt(M)+1;
    int i, j;
    for(i=2; i*i<=n; i++)
    {
        if(arr[i]==0)
        {
            for(j=i+i; j<=n; j+=i) arr[j]=1;
        }
    }
    arr[0]=1, arr[1]=1;
    for(i=1; i<=n; i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            dp[i]= dp[i-1]+1;
        }
        else dp[i]= dp[i-1];
    }
}
ld segmented_sieve(ld a, ld b)
{
    mark=0;

    ld i, l= prime.size(), cnt=0;
    ld low= a;
    ld high= b;
    if(a<=n)
    {
        low= n+1;
        cnt= dp[n]-dp[a-1];
    }
    for(i=0; i<l; i++)
    {
        int ll= (low/prime[i])*prime[i];
        if(ll<low) ll+=prime[i];
        for(ld j= ll; j<=high; j+=prime[i])
        {
            mark[j-low]= 1;
        }
    }
    for(i=low; i<=b; i++)
    {
        if(mark[i-low]==0) cnt++;
    }
    return cnt;
}
int main()
{
    sieve();
    ld t,kase=1, a, b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;

        cout<<"Case "<<kase++<<": ";
        if(a<=n && b<=n){
            cout<<dp[b]-dp[a-1]<<endl;
        }
        else
        cout<<segmented_sieve(a, b)<<endl;

    }


}
