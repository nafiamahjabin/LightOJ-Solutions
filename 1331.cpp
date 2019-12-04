#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        double r1, r2, r3, x, y, z, ans;
        cin>>r1>>r2>>r3;
        x=r2+r3;
        y=r3+r1;
        z=r1+r2;
        double X= acos((y*y+z*z-x*x)/(2*y*z));
        double Y= acos((x*x+z*z-y*y)/(2*x*z));
        double Z= acos((y*y+x*x-z*z)/(2*y*x));
        double s= (x+y+z)/2;
        ans= sqrt(s*(s-x)*(s-y)*(s-z));
        ans= ans-(0.5*(r1*r1*X+r2*r2*Y+r3*r3*Z));
        printf("Case %d: %lf\n", cs++,ans);
    }
}
