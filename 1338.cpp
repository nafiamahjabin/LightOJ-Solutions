#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i,cs=1;
    cin>>t;
    getchar();
    while(t--)
    {

        char name1[110], name2[110];
        gets(name1);
        // getchar();
        gets(name2);
        string s1, s2;
        int l1=strlen(name1);
        for(i=0; i<l1; i++)
        {
            if(name1[i]!=' ')
            {
                name1[i]=tolower(name1[i]);
                s1+=name1[i];
            }
        }
        int l2=strlen(name2);
        for(i=0; i<l2; i++)
        {
            if(name2[i]!=' ')
            {
                name2[i]=tolower(name2[i]);
                s2+=name2[i];
            }
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());


        if(s1==s2)
        {
            cout<<"Case "<<cs++<<": Yes\n";
        }
        else
        {
            cout<<"Case "<<cs++<<": No\n";
        }

    }
}
