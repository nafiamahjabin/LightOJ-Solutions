#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int n,i, arr[110], pos[110];
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>arr[i];
            pos[arr[i]]=i;
        }
        int cnt=0;
        bool flag=false;
        while(flag==false)
        {
            flag=true;
            for(i=1; i<=n; i++)
            {
                if(pos[arr[i]]!=arr[i])
                {
                    flag=false;
                    pos[arr[i]]=arr[i];
                    swap(arr[i], arr[arr[i]]);
                    pos[arr[i]]=i;
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n",cs++,cnt);

    }
}
