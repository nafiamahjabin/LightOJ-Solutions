#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        double a, b;
        scanf("%lf : %lf", &a, &b);
        double r= sqrt(a*a+b*b)/2.0;
        double theta =  acos((r*r+r*r-b*b)/(2.0*r*r));
        double s = r*theta;
        double x = 400.00/(2.0*s+2.0*a);
        double ans1=x*a;
        double ans2=x*b;
        printf("Case %d: %f %f\n", cs++,ans1,ans2);
    }
}
