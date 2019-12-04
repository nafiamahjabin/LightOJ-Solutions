#include<bits/stdc++.h>
using namespace std;
bool is_prime[10000002];
int prime[1000000], total_prime;
void sieve()
{
    int i, n=10000002;

    int root=sqrt(n)+1;
    for(i=2; i<=root; i++)
    {
        if(is_prime[i]==0)
        {
            for(int j=i+i; j<=n; j+=i)
                is_prime[j]=1;
        }
    }
    is_prime[1]=1;is_prime[0]=1;
    for(i=2; i<n; i++)
    {
        if(is_prime[i]==0)
        prime[total_prime++]=i;
    }
}
int main()
{
    sieve();
    long long int n, t,cs=1,i, a, b, sum;
    scanf("%lld", &t);
    while(t--)
    {
        sum=0;
        scanf("%lld", &n);
        printf("Case %lld: ", cs++);
        for(i=0; prime[i]<=n/2 && i<total_prime; i++)
        {
            a=n-prime[i];
            if(is_prime[a]==0 && a>=prime[i])
            {
                sum++;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
