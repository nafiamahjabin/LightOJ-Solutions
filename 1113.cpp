#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    int t, cs=1;
    cin>>t;
    while(t--)
    {
        string s, u;
        stack<string>st;
        stack<string>q;
        st.push("http://www.lightoj.com/");
        printf("Case %d:\n", cs++);
        while(cin>>s)
        {
            if(s=="QUIT") break;
            if(s=="VISIT")
            {
                cin>>u;
                st.push(u);
                while(q.size()) q.pop();
                cout<<u<<endl;
            }
            else if(s=="BACK")
            {
                if(st.size()>1){
                q.push(st.top());
                st.pop();
                cout<<st.top()<<endl;
                }

                else cout<<"Ignored\n";

            }
            else if(s=="FORWARD")
            {
                if(q.size()){
                st.push(q.top());
                cout<<q.top()<<endl;
                q.pop();
                }

                else cout<<"Ignored\n";

            }
        }
    }
}
