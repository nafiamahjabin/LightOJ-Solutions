#include<bits/stdc++.h>
using namespace std;
#define mx 5000001
#define ll unsigned long long int
bool a[mx];
ll phi[mx], c;

vector<int> prime;

void numberOfPhi()
{
    for(int i=2; i<mx; i++)
    {
        phi[i]=i;
    }
    for(int i=2; i<mx; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<mx; j+=i)
            {
                phi[j]-= (phi[j]/i);
            }
        }
    }
}
void pre()
{
    numberOfPhi();
    int i;
    phi[1]=0;
    for(i=2; i<mx; i++)
    {
        ll x = phi[i];
        phi[i]=phi[i-1]+x*x;
    }
}
int main()
{
    pre();
    ll i,t, cs=1, x, y, sum;
    scanf("%llu", &t);
    while(t--)
    {
        sum=0;
        scanf("%llu%llu", &x, &y);
        sum = phi[y]-phi[x-1];
        printf("Case %llu: %llu\n", cs++, sum);

    }
    return 0;
}
