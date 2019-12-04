#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000];
int main()
{
    int i,j, maxx=0;

    for(i=1; i<=1000; i++)
    {
        int cnt=0;
        for(j=1; j*j<=i; j++)
        {
            if(i%j==0)
            {
                int x=i/j;
                if(j!=x) cnt+=2;
                else cnt++;
            }
        }
        maxx=max(maxx, cnt);
        v[cnt].push_back(i);
    }
    vector<int>ans;
    for(i=1; i<=maxx; i++)
    {
        int l=v[i].size();
        if(l!=0)
        {
            for(j=l-1; j>=0; j--)
            {
                ans.push_back(v[i][j]);
            }
        }
    }
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>i;
        printf("Case %d: ", cs++);
        cout<<ans[i-1]<<endl;
    }

}
