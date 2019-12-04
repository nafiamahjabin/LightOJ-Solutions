#include<stdio.h>
int main(){
    int i, j,sum, t, n, a;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        scanf("%d", &n);
        sum=0;
        for(j=0; j<n; j++){
            scanf("%d", &a);
            if(a<=0){
                sum= sum;
            }
            else{
                sum= sum+a;
            }
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}
