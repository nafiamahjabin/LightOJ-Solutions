#include<bits/stdc++.h>
using namespace std;
double check(double x, double y, double mid)
{
    double h1=sqrt(x*x-mid*mid);
    double h2=sqrt(y*y-mid*mid);

    double h = (h1*h2)/(h1+h2);
    return h;

}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        double x, y, h;
        cin>>x>>y>>h;

        double lo=0.0, hi=min(x,y);
        int cnt=100;

        while(cnt--)
        {
            double mid= (lo+hi)/2.0;

            if(check(x,y,mid)<=h)
                hi=mid;
            else lo=mid;
        }
        printf("Case %d: %f\n", cs++,lo);
    }
}

