#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t, n,cs=1;
    char s[10];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        scanf("%s", s);
        printf("Case %d: ", cs++);
        if(s[0]=='A')
        {
            if(n%3==1) printf("Bob\n");
            else printf("Alice\n");

        }
        else
        {
            if(n%3==0) printf("Alice\n");
            else printf("Bob\n");
        }
    }
}
