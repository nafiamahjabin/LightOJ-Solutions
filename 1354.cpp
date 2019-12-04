#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int a[5],l,test,t, b, c,ch,a1, d, e,k,count,f, i, j, flag,flag1;
    char s[100];
    scanf("%d", &test);
    for(t=1; t<=test; t++){
    scanf("%d%c%d%c%d%c%d",&a1,&ch,&b,&ch,&c,&ch,&d);
    getchar();
    scanf("%s", &s);
    a[0]=a1,a[1]=b,a[2]=c,a[3]=d;
    flag1=0;
    l=strlen(s);
    s[l]='.';
    count=0;
    for(i=0,f=0; i<=l; i++){
        e=0;
        if(s[i]=='.'){
            flag=i;
            for(j=flag-1, k=0; j>=flag1;k++, j--){
                s[j]=s[j]-'0';
                e=e+s[j]*pow(2,k);

            }

            if(e==a[f]){
                count++;
                f++;
            }
            else{
                f++;
            }
            flag1=flag+1;
        }
    }
    if(count==4){
        printf("Case %d: Yes\n", t);
    }
    else{
        printf("Case %d: No\n", t);
    }
    }
    return 0;
}
