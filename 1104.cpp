#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, y, t, cs=1;
    cin>>t;
    while(t--)
    {
        cin>>y;
        double p=1.0;
        for(a=1; p>.5; a++)
        {
            p*=(1.0-(double)a/y);
        }
        cout<<"Case "<<cs++<<": ";
        cout<<a-1<<endl;


    }
}
