#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>prime;
int pre[101][101];
void sieve()
{
    bool mark[101] = {0};
    int i,j;
    for(i=2; i*i<=100; i++)
    {
        if(mark[i]==0) for(j=i+i; j<=100; j+=i) mark[j]=1;
    }

    for(i=2; i<=100; i++) if(mark[i]==0)  prime.pb(i);
}
int main()
{
    sieve();
    int i, j;
    for(i=1; i<=100; i++)
    {
        int x=i;
        for(j=0; prime[j]*prime[j]<=x; j++)
        {
            if(x%prime[j]==0)
            {
                int cnt=0;
                while(x%prime[j]==0)
                {
                    cnt++;
                    x/=prime[j];

                }
                pre[prime[j]][i]=cnt;


            }
        }
        if(x>1) {
            pre[x][i]++;
        }
    }
    int l=prime.size();
    for(j=0; j<l; j++)
        for(i=2; i<=100; i++)
        {
            pre[prime[j]][i]+=pre[prime[j]][i-1];
        }
    int n, t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        vector<int>an;
        for(i=0; i<l; i++)
        {
            if(pre[prime[i]][n]>0) an.pb(prime[i]);

        }
        printf("Case %d: %d = ", cs++,n);
        int ln=an.size();
        for(i=0; i<ln-1; i++) cout<<an[i]<<" ("<<pre[an[i]][n]<<") * ";
            cout<<an[ln-1]<<" ("<<pre[an[ln-1]][n]<<")\n";
    }


}
