#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, kase=1, l, i, t, mod, nmbr;
    char s[500];
    cin >> t;
    while(t--)
    {
        cin >> s >> n;
        l= strlen(s);
        nmbr=0;
        n= abs(n);
        for(i=0; i<l; i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                nmbr=nmbr*10 + (s[i] - '0');

                if(nmbr>=n)
                {
                    int x = nmbr/n;
                    nmbr = nmbr-(x*n);
                }
            }
        }
        if(nmbr==0)
        printf("Case %d: divisible\n", kase++);
        else
        printf("Case %d: not divisible\n", kase++);
    }
    return 0;
}
