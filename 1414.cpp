#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s1[100], s2[100],c;
    long long int i, x1,j, y1,x3, x2, y2, t=0;
    scanf("%lld",&j);
    getchar();
    while(j--)
    {
        t++;
        long long int cont=0;
        scanf("%s%lld%c%lld%s%lld%c%lld",s1, &x1,&c,&y1, s2,&x2,&c,&y2);
        if(strcmp(s1,"January")!=0 && strcmp(s1, "February")!=0)
        y1++;

        if(strcmp(s2,"January")==0 || ((strcmp(s2, "February")==0) && x2<29))
        y2--;
        if(y2-y1<0){
        printf("Case %lld: 0\n", t);
        continue;
        }
        x1=(y2/4)-((y1-1)/4);
        x2=(y2/100)-((y1-1)/100);
        x3=(y2/400)-((y1-1)/400);
        cont=x1-x2+x3;

        printf("Case %lld: %lld\n", t, cont);
    }
    return 0;
}
