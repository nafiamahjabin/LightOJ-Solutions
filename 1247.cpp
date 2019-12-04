#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int i, n, cnt=0, m;
        cin>>n>>m;
        long long int x,xr;

        printf("Case %d: ", cs++);
        vector<long long int>v;
        for(i=0; i<n; i++)
        {
            cnt=0;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                cnt+=x;
            }
            v.push_back(cnt);
        }
        n=v.size();
        xr=v[0];
        for(i=1; i<n; i++)
        {
            xr^=v[i];
        }
        if(xr==0) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;

    }
}
