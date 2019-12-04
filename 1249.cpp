#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int n, arr[110], i=0,a,b,c;
        string s;
        cin>>n;
        cout<<"Case "<<cs++<<": ";
        if(n==1)
        {
            arr[0]=1;
            arr[1]=1;
            n--;
        }
        map<int, string>mp;
        while(n--)
        {
            cin>>s>>a>>b>>c;
            arr[i]=a*b*c;
            mp[arr[i]]=s;
            i++;
        }
        sort(arr, arr+i);
        if(arr[0]<arr[1])
        {
            cout<<mp[arr[i-1]]<<" took chocolate from "<<mp[arr[0]]<<endl;
        }
        else
        {
            cout<<"no thief\n";
        }
    }
}
