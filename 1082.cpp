#include<bits/stdc++.h>
using namespace std;
int getmid(int s,int e);
int *construct(int arr[], int n);
int construct_tree(int arr[], int start, int end, int *st, int i);
int getmin(int *st, int s, int e, int l, int r, int i);
int main()
{
    int n,kase=1, arr[100005], t, i, q, l, r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &q);
        for(i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Case %d:\n", kase++);
        int *st= construct(arr, n);

        while(q--)
        {
            scanf("%d %d",&l, &r);
            printf("%d\n",getmin(st, 0, n-1, l-1, r-1, 0));
        }
    }
    return 0;
}
int *construct(int arr[], int n)
{
    int height= (int)(ceil(log2(n)));
    int max_size= 2* (int)pow(2,height)-1;
    int *st= new int[max_size];
    construct_tree(arr, 0, n-1, st, 0);
    return st;
}
int construct_tree(int arr[], int start, int end, int *st, int i)
{
    if(start==end)
    {
        st[i]= arr[start];
        return arr[start];
    }
    int mid= getmid(start, end);
    st[i]= min(construct_tree(arr, start, mid, st, i*2+1), construct_tree(arr, mid+1, end, st, i*2+2));

    return st[i];
}
int getmid(int s,int e)
{
    return s+(e-s)/2;
}
int getmin(int *st, int s, int e, int l, int r, int i)
{
    if(l<=s && r>=e)
    {
        return st[i];
    }
    else if(r<s || l>e)
    {
        return INT_MAX;
    }
    int mid= getmid(s, e);
    return  min(getmin(st, s, mid, l, r, i*2+1), getmin(st, mid+1, e, l, r, i*2+2));
}

