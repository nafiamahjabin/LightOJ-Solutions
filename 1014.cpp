#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000005];
int main()
{
    ll p, n,i, t, cs=1;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &p);
        ll q= n-p;
        printf("Case %lld: ", cs++);


        memset(arr, 0, sizeof(arr));
        ll j=0, root=sqrt(q);
        root++;
        for(int i=1; i<root; i++)
        {
            if(q%i==0)
            {
                ll x= q/i;
                if(i>p )
                arr[j++]=i;
                if(x!=i)
                {
                    if(x>p)
                   arr[j++]=x;
                }

            }
        }
        if(j==0)
        {
            printf("impossible\n");
            continue;
        }
        sort(arr, arr+j);
        for(i=0; i<j; i++)
        {
            if(i!=0) printf(" ");
            printf("%lld", arr[i]);
        }
        cout<<endl;
    }

}
