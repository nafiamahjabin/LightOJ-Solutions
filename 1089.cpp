#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
struct que
{
    int l, r;
} q[50005];
int main()
{
    vector<int>v;
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, a,I,j=0, b;
        memset(q,0,sizeof(q));
        v.clear ();
        mp.clear();
        scanf("%d %d", &n, &m);
        for(I=0; I<n; I++)
        {
            scanf("%d %d", &a, &b);

            if(mp[a]==0)
                v.push_back(a);
            mp[a]=1;
            if(mp[b]==0)
                v.push_back(b);
            mp[b]=1;
            q[I].l=a;
            q[I].r=b;
        }
        sort(v.begin(),v.end());

        mp.clear ();
        int l=v.size();
        for(I=0; I<l; I++)
            mp[v[I]]=j++;
        int arr[l+5]= {0};
        int last[l+5]= {0};

        for(I=0; I<n; I++)
        {
            arr[mp[q[I].l]]++;
            arr[mp[q[I].r]+1]--;
            last[mp[q[I].r]]++;
        }
        for(I=1; I<=l; I++)
            arr[I]+=arr[I -1];

        printf("Case %d:\n", cs++);
        while(m--)
        {
            scanf("%d", &a);

            int it=lower_bound(v.begin(),v.end(),a)-v.begin();

            if(v[it]!=a) {
                    it--;
                printf("%d\n",arr[mp[v[it]]]-last[mp[v[it]]]);


                continue;
            }
            if(a>v[l-1] || a<v[0])
            {
                printf("0\n");

                continue;
            }
            printf("%d\n",arr[mp[v[it]]]);

        }

    }
}
