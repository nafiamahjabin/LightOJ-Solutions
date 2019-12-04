#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int cs=1, t;
    cin>>t;
    while(t--)
    {
        printf("Case %d: ", cs++);
        int n, arr[10005],mp[10005]= {0}, i,j;
        cin>>n;
        bool flag=true;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];

            if(arr[i]>=n)
            {
                flag=false;
            }
            if(flag)
                mp[arr[i]]++;
        }
        for(i=0; i<n; i++)
        {
            int x= mp[arr[i]];
            if(x>=3)
            {
                flag=false;
                break;
            }
            if(x==2)
            {
                if(mp[n-1-arr[i]]!=0)
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag) cout<<"yes\n";
        else cout<<"no\n";
    }
}
