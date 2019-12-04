#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,y1,x2,y2, x, y,kase=1, t, n;
    cin >> t;
    while(t--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        cout << "Case "<< kase++<<":\n";
        while(n--)
        {
            cin >> x >> y;
            if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}
