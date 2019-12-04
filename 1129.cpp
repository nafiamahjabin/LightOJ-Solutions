#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node
{
    bool endmark;
    node *next[10];
    node()
    {
        endmark=false;
        for(int i=0; i<10; i++) next[i]=NULL;
    }
}*root;
void insert(string s)
{
    int l=s.size();
    node *cur=root;
    for(int i=0; i<l; i++)
    {
        int id=s[i]-'0';
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur= cur->next[id];
    }
    cur->endmark=true;
}
bool check(string s)
{
    int l=s.size();
    node *cur=root;
    for(int i=0; i<l; i++)
    {
        int id= s[i]-'0';
        if(cur->next[id]==NULL) return false;
        cur=cur->next[id];
    }
    if(cur->endmark==true)
    {
        for(int i=0; i<10; i++)
        {
            if(cur->next[i]!=NULL) return false;
        }
    }
    return true;
}
void del(node *cur)
{
    for(int i=0; i<10; i++)
    {
        if(cur->next[i]) del(cur->next[i]);
    }
    delete(cur);

}
int main()
{
    FastRead;
    int t,i, n, cs=1;

    cin>>t;
    while(t--)
    {
        string s[10006];
        cin>>n;
        root=new node();
        for(i=0; i<n; i++)
        {
            cin>>s[i];
            insert(s[i]);
        }
        bool flag=true;
        for(i=0; i<n; i++)
        {
            if(check(s[i])==false)
            {
                flag=false;
                break;
            }
        }
        cout<<"Case "<<cs++<<": ";
        if(flag==true)
        {

            cout<<"YES\n";
        }
        else cout<<"NO\n";
        del(root);
    }


}
