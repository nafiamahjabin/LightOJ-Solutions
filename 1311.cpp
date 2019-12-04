#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        double v1,v2,v3,a1,a2;
        cin>>v1>>v2>>v3>>a1>>a2;
        double d1 = (v1*v1)/(2.0*a1);
        double d2 = (v2*v2)/(2.0*a2);
        double d = d1+d2;
        double tm = max(v1/a1, v2/a2);

        double s = v3*tm;
        printf("Case %d: %f %f\n",cs++,d,s);
    }
}
