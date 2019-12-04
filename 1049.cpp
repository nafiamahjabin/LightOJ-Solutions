#include<bits/stdc++.h>
using namespace std;
int v1[300];
int v2[300];
bool vis[300];

int main()
{
    int n, m, i, j, t, cs=1;


    scanf("%d", &t);
    while(t--)
    {
        memset(v1,0, sizeof(v1));
        memset(v2,0, sizeof(v2));

        scanf("%d", &n);
        int a, b, c;
        int cnt1=0;
        int cnt2=0;
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if(!v1[a] && !v2[b])
            {
                cnt1+=c;
                v1[a]=v2[b]=1;
            }
            else
            {
                cnt2+=c;
                v2[a]=v1[b]=1;
            }

        }
        int ans=min(cnt1,cnt2);
        printf("Case %d: %d\n",cs++, ans);

    }

}
