#include<stdio.h>
int main()
{
    int n, i,j=0, cont,m, x,y,t;
    scanf("%d", &t);
    while(t--){
        j++;
        cont=0,y=2;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &x);
            y=x-y;
            m=0;
            if(y%5==0)
            m=y/5;
            else{
            m=(y/5)+1;
            }
            cont+=m;
            y=x;
        }

        printf("Case %d: %d\n", j, cont);
    }
    return 0;
}
