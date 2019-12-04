#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int i,j,r,c;
        cin>>r>>c;
        long long int x=0, v;
        for(i=1;i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                scanf("%lld", &v);
                if((r+c-i-j)%2!=0) x^=v;

            }
        }
        if(x==0) printf("Case %d: lose\n",cs++);
        else  printf("Case %d: win\n",cs++);


    }
}
