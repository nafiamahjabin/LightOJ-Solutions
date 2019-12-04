#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[110], i;
        for(i=0; i<n; i++) cin>>arr[i];
        int s=0, cnt=0;

        for(i=0; i<n; i++)
        {
            s+=abs(arr[i]);
            if(arr[i]<0) cnt++;
        }
        printf("Case %d: ", cs++);
        if(cnt==n)
        {
            cout<<"inf\n";
            continue;
        }
        n-=cnt;
        int x= __gcd(s,n);
        cout<<s/x<<"/"<<n/x<<endl;


    }

}
