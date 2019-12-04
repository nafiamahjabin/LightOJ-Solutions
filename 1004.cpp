#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll mat[210][210],i,j,k,cs=1, n,t;
    scanf("%lld", &t);
    while(t--)
    {
        for(i=0; i<=202; i++)
        {
            for(j=0; j<=202; j++) mat[i][j]=0;
        }
        scanf("%lld", &n);
        ll nn=n;
        n*=2;
        n--;


        for(i=1, k=0; i<=n ; i++)
        {
            ll m=0;
            for(j=1; j<=n; j++)
            {
                if(j>=nn-k && j<=nn+k)
                {
                    if(m%2==0)
                    {
                        scanf("%lld", &mat[i][j]);
                    }
                    else mat[i][j]=0;
                    m++;
                }
                else mat[i][j]=0;
            }
            if(i<nn) k++;
            else k--;
        }
        for(i=n-1, k=0; i>0 ; i--)
        {
            for(j=1; j<=n; j++)
            {
                mat[i][j]= mat[i][j]+max(mat[i+1][j+1], mat[i+1][j-1]);
            }
        }
        ll sum=0;
        for(i=1; i<=n; i++) sum= max(sum, mat[1][i]);

        printf("Case %lld: ", cs++);
        printf("%lld\n", sum);
    }
    return 0;
}
