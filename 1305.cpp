#include<stdio.h>
#include<math.h>
int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4, area, t, i=0;
    scanf("%d", &t);
    while(t--){
    i++;
    scanf("%d%d%d%d%d%d", &x1,&y1,&x2, &y2,&x3,&y3);
    x4=x1+x3-x2;
    y4=y1+y3-y2;
    area=((x1*y2+x2*y3+x3*y4+x4*y1)-(y1*x2+y2*x3+y3*x4+y4*x1));
    area*=(0.5);
    printf("Case %d: %d %d %d\n",i, x4, y4, abs(area));
    }
    return 0;
}
