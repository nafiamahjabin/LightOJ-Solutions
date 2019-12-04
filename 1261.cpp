#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,t, cs=1;
    cin>>t;
    while(t--)
    {
        int arr[40][40];
        cin>>n>>m>>k;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<k; j++) cin>>arr[i][j];
        }
        int p,a[40];
        cin>>p;
        int oc[40]={0};
        for(int i=0; i<p; i++) {
            cin>>a[i];
            oc[a[i]]++;
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                if(arr[i][j]<0)
                {
                    if(oc[abs(arr[i][j])]==0) {cnt++;break;}
                }
                else
                {
                    if(oc[arr[i][j]]>=1)
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }
        if(cnt==n) cout<<"Case "<<cs++<<": Yes"<<endl;
        else cout<<"Case "<<cs++<<": No"<<endl;

    }

}
