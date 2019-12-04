#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll mat[60][5],cs=1,i, j, n, t;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(i=1; i<=n; i++)
        {
            mat[i][0]=INT_MAX;
            for(j=1; j<=3; j++)
            {
                scanf("%lld", &mat[i][j]);
            }
            mat[i][j]=INT_MAX;
        }

        ll a,b;
        for(i=n-1; i>=1; i--)
        {
            for(j=1;j<=3; j++)
            {
                if(j==1)
                {
                    a=2, b=3;
                }
                else if(j==2)
                {
                    a=1,b=3;
                }
                else
                {
                    a=1,b=2;
                }
                mat[i][j]=mat[i][j]+min(mat[i+1][a], mat[i+1][b]);
            }
        }
        ll ans=INT_MAX;
        for(i=1;i<=3; i++) ans=min(ans, mat[1][i]);
        printf("Case %lld: ", cs++);
        cout<<ans<<endl;
    }
}
