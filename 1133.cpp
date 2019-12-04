#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, kase=1,d, i,j, a[110], num, m;
    char c;
    cin >> t;
    while(t--)
    {
        cin >> n>> m;
        for(i=0; i<n; i++)
        {
            cin >> a[i];
        }
        while(m--)
        {
            cin >> c;
            if(c=='S')
            {
                cin >> d;
                for(i=0; i<n; i++)
                {
                    a[i]+=d;
                }
            }
            else if(c=='M')
            {
                cin >> d;
                for(i=0; i<n; i++)
                {
                    a[i]*=d;
                }
            }
            else if(c=='D')
            {
                cin >> d;
                for(i=0; i<n; i++)
                {
                    a[i]/=d;
                }
            }
            else if(c=='R')
            {
                for(i=0, j=n-1; i<n/2; i++, j--)
                {
                    d= a[i];
                    a[i] = a[j];
                    a[j] = d;
                }
            }
            else if(c=='P')
            {
                int  o;
                cin >> j >> o;
                num= a[j];
                a[j]= a[o];
                a[o] = num;
            }
        }
        cout << "Case " << kase++ << ":\n";
        for(i=0; i<n; i++)
        {
            cout << a[i];
            if(i!=n-1)
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
