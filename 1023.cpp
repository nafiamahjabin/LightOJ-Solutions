#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int t, n, k, i, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        s.clear();
        scanf("%d %d", &n, &k);
        for(i='A'; i<n+'A'; i++)
        {
            s+=(char)i;
        }
        printf("Case %d:\n", cs++);
        i=0;
        do
        {
            if(i==k) break;
            i++;
            cout<<s<<endl;

        }while(next_permutation(s.begin(), s.end()));
    }
}
