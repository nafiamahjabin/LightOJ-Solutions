#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[4];
    int cnt;
    node()
    {
        cnt=0;
        endmark=false;
        for(int i=0; i<4; i++) next[i]=NULL;
    }

} *root;
int ans;
int value(char c)
{
    if(c=='A') return 0;
    else if(c=='C') return 1;
    else if(c=='G') return 2;
    else if(c=='T') return 3;
}

void insert(string s)
{
    int len=s.size();
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id= value(s[i]);
        if(curr->next[id]==NULL)
        {
            curr->next[id]=new node();
        }
        curr->cnt=curr->cnt+1;
        curr=curr->next[id];

    }
    curr->cnt=curr->cnt+1;

    curr->endmark=true;

}
void search(string s)
{
    int len= s.size();
    node *curr= root;
    for(int i=0; i<len; i++)
    {
        int id= value(s[i]);
        curr= curr->next[id];
        ans=max(ans, curr->cnt*(i+1));
    }
    ans=max(ans, curr->cnt*(len));

}
void del(node* cur)
{
    for(int i=0; i<4; i++)
    {
        if(cur->next[i]) del(cur->next[i]);
    }
    delete(cur);
}
int main()
{

    int t, n,i,cs=1;

    cin>>t;
    while(t--)
    {
        root= new node();

        string s[50005];
        cin>>n;
        ans=-INT_MAX;
        for(i=0; i<n; i++)
        {
            cin>>s[i];
            insert(s[i]);
        }

        for(i=0; i<n; i++)
        {
            search(s[i]);

        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        del(root);
    }
}


