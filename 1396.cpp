#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0)
#define sz 101000
int main()
{

    int t, cs=1;
    cin>>t;
    while(t--)
    {
        int i, j;
        char s[sz],r[sz];

        scanf("%s", s);
        int l=strlen(s);
        strcpy(r,s);

        for(i=0, j=l-1; i<l/2; i++, j--)
        {
            r[i]=r[j]=s[i];
        }
        bool flg=false;
        for(int i=0; i<l; i++)
        {
            if(r[i]>s[i])
            {
                flg=true;
                break;
            }
            else if(r[i]<s[i]) break;
        }
        if(!flg)
        {
            if(l%2) i=j=l/2;
            else
            {
                i=l/2-1;
                j=l/2;
            }
            for(; i>=0;j++,i--)
            {
                if(r[i]<'9')
                {
                    r[i]++;
                    r[j]=r[i];
                    break;
                }
                else
                {
                    r[i]='0';
                    r[j]='0';
                }
            }
            if(r[0]=='0')
            {
                r[0]='1';
                r[l]='1';
                r[l+1]='\0';
            }

        }
        printf("Case %d: %s\n",cs++,r);

    }
}
