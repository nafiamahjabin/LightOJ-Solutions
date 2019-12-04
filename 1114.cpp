#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max 100000
#define alph 52
int value(char c)
{
    if(c>='A' && c<='Z') return c-'A';
    return c-'a'+26;
}
struct trie
{
    int n, root;
    int next[max][alph];
    ll data[max];
    void init()
    {
        n=1, root=0;
        memset(next[root], -1, sizeof(next[root]));
        memset(data, 0, sizeof(data));
    }
    void insert(string s)
    {
        int curr=root,  l=s.size();
        for(int i=0; i<l; i++)
        {
            int id= value(s[i]);
            if(next[curr][id]==-1)
            {
                next[curr][id]=n;

                memset(next[n], -1, sizeof(next[n]));
                n++;
            }
            curr= next[curr][id];
        }
        data[curr]++;
    }
    ll check(string s)
    {
        int curr=root, l=s.size();
        for(int i=0; i<l; i++)
        {
            int id= value(s[i]);
            if(next[curr][id]==-1) return 0;
            curr= next[curr][id];
        }
        return data[curr];
    }

}tree;
int main()
{
    int i, n, t, m, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        char s[110], st[100005];
        tree.init();
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%s", s);
            int l=strlen(s);
            if(l>2) sort(s+1,s+l-1);
            tree.insert(s);
        }
        scanf("%d", &m);
        getchar();
        printf("Case %d:\n", cs++);
        for(i=0; i<m; i++)
        {
            int sum=1;
            scanf("%[^\n]s",st);
            int l=strlen(st);

            if(st[l-1]=='\n')
            {
                printf("1\n");
                continue;
            }
            st[l]=' ';
            memset(s, '\0', sizeof(s));
            for(int j=0, k=0; j<=l; j++)
            {
                if(st[j]!=' ')s[k++]+=st[j];
                if(st[j-1]!=' ' && st[j]==' ')
                {
                    s[k]='\0';
                    if(k>2) sort(s+1, s+k-1);

                    if(k>0)
                    sum*=(tree.check(s));
                    k=0;
                    memset(s, '\0', sizeof(s));
                    while(st[j]==' ')j++;
                    j--;
                }
            }
            printf("%d\n", sum);
            getchar();
            memset(st, '\0', sizeof(st));
        }
    }
}
