#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int n, d, cnt=0,dd;
        scanf("%d %d", &n, &d);
        dd=d;
        while(d%n!=0)
        {
            d=(d*10+dd)%n;
            cnt++;
        }
        printf("Case %d: %d\n",cs++,cnt+1);
    }
}
