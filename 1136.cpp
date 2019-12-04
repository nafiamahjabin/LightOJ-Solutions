#include<stdio.h>
int main()
{
    long long int t,i,d = 0,x,y;
    scanf("%lld", &t);
    while(t--)
    {
        d++;
        scanf("%lld%lld", &x, &y);
        i = (((y/3)*2) +(y%3)/2) - ((((x-1)/3)*2) +((x-1)%3)/2);
        printf("Case %lld: %lld\n", d, i);
    }
}
