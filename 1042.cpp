#include<bits/stdc++.h>
using namespace std;
int main()
{

    unsigned i, j, k;
    int l, sum = 0;
    int tc, t, d, x, y, r, n, current, first;
    char ch;
    bool flag;

    scanf("%d", &tc);
    getchar();

    for(t = 1; t <= tc; t++)
    {
        scanf("%d", &n);

        for(i = 1; i <= 1<<31 ; i <<= 1)
        {
            if(i & n)
                break;
        }

        k = 0;
        while(i <= 1<<31)
        {
            if(!(i & n)) break;
            n &= ~i;
            k++;
            i <<= 1;
        }
        n |= i;

        for(j = 1, i = 1; j < k; i <<= 1, j++)
            n |= i;

        printf("Case %d: %d\n", t, n);
    }

    return 0;
}

