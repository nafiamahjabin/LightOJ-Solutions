#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[300004];
int main()
{
    ll n, t, cs=1 , i, ans;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        stack<int>st;
        ans=-1;
        printf("Case %lld: ", cs++);
        for(i=0; i<n; i++) scanf("%lld", &arr[i]);
        for(i=0; i<n; )
        {
            if(st.empty() || arr[i]>=arr[st.top()])
            {
                st.push(i++);
            }
            else
            {
                int tp= st.top();
                st.pop();
                ll sum= arr[tp]*(st.empty()?i:(i-st.top()-1));
                ans= max(ans, sum);
            }
        }
        while(st.size())
        {

                int tp= st.top();
                st.pop();
                ll sum= arr[tp]*(st.empty()?i:(i-st.top()-1));
                ans= max(ans, sum);
        }
        printf("%lld\n", ans);
    }
}
