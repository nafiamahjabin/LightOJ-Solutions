#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    double r, R, n;
    cin>>t;
    while(t--)
    {
        cin>>R>>n;
        double x= sin(acos(-1)/n);
        double one= x*R;
        double ans= one/(x+1);
        printf("Case %d: %lf\n", cs++, ans);
    }
}
