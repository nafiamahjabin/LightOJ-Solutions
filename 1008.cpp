#include<stdio.h>
#include<math.h>
#define ll long long int
int main()
{
    ll n,row, clm, x, t,i=0;
    scanf("%lld", &t);
    while(t--)
    {
        i++;
        scanf("%lld", &n);
        x=sqrt(n);
        if(x*x!=n)
        x++;
        if(x*x-n<x)
        {
            row=x;
            clm=x*x-n+1;
        }
        else
        {
            clm=x;
            row= -x*x+2*x+n-1;
        }
        if(x%2!=0)
        {
            ll swap= row;
            row= clm;
            clm=swap;
        }
        printf("Case %lld: %lld %lld\n", i, row, clm);
    }
    return 0;
}

