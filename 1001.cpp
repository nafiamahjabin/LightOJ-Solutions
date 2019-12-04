#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a=0, b;
        if(n==0)
            b= 0;
        else
            b=n;
        if(b>10)
        {
            b= 10;
            a=n-10;
        }
        cout << a <<" " <<b <<'\n';
    }
    return 0;

}
