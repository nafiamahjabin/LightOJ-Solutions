#include<bits/stdc++.h>
using namespace std;
#define sz 151111
int arr[151111], tmp[sz] ,n, segOne[4*sz] ;
struct st
{
    char c;
    int x;
} query[51111];
int bl(int s, int e, int i)
{
    if(s<=0 || e>n|| s>e) return 0;
    if(s==e) return segOne[i]=tmp[s];
    int m= (s+e)/2;
    return segOne[i]=bl(s, m, i*2 )+bl(m+1, e, i*2+1);
}
int upOne(int s, int e, int i, int vl, int  in)
{
    if(s==e) return segOne[i]=vl ;
    int m =(s+e)/2, u=segOne[i*2 ], v=segOne[i*2+1];
    if(m>=in )  u= upOne(s, m, i*2 , vl, in);
    else v=upOne(m+1, e, i*2+1, vl, in);
    return segOne[i]= u+v;

}
int getSum(int s, int e, int i, int l, int r )
{
    if(r<s||l>e) return 0;
    if(s>=l && e<=r) return segOne[i];
    int m= (s+e)/2;
    return getSum(s, m, i*2 , l, r)+ getSum(m+1, e, i*2+1, l, r) ;
}
int main()
{
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        memset(tmp, 0, sizeof(tmp));
        memset(segOne, 0, sizeof(segOne));
        int q,nn, i,x;
        char ch;
        scanf("%d %d", &nn, &q);
        n=nn+q ;
        for(i=1; i<=nn ; i++)
        {
            scanf("%d", &arr[i]);
            tmp[i]=1;
        }
        printf("Case %d:\n", cs++);
        for(i=1; i<=q; i++)
        {
            cin>>query[i].c>>query[i].x;
        }

        bl(1, n , 1);
        for(i=1; i<=q; i++)
        {
            ch= query[i].c;
            x= query[i].x ;
            if(ch=='a')
            {
                arr[++nn ]=x;
                tmp[nn ]=1;
                upOne(1, n, 1,1, nn );
                continue;
            }
            int b=1, e=nn , m=(b+e)/2, ans=-1;
            while(b<=e)
            {
                int sum= getSum(1, n, 1, 1, m);
                int sum1= getSum(1,n,1,1,m-1);
                if(sum!=sum1&& sum==x)
                {
                    ans=m;
                    break;
                }
                if(sum<x) b=m+1;
                else e=m-1;
                m=(b+e )/2;
            }
            if(ans==-1)
            {
                printf("none\n");
            }
            else
            {
                printf("%d\n", arr[ans]);
                tmp[ans]=0;
                upOne(1, n, 1, 0, ans);
            }


        }
    }
}
