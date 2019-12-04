#include<stdio.h>
int main(){
    double c, sq, a, r, pi;
    int i, t;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
    pi=acos(-1);
    scanf("%lf", &r);
    c=pi*r*r;
    a=r+r;
    sq=(a*a)-c;
    printf("Case %d: %.2lf\n",i, sq);
    }
    return 0;
}
