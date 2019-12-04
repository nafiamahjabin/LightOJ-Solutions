#include<bits/stdc++.h>
using namespace std;
char s[1000], r[1000];
int main(){
    long long int n, j,i,x,m,t, cs=1, count;
    scanf("%d", &t);
    while(t--){
        printf("Case %d: ", cs++);
        scanf("%d", &n);
            for(i=0;n>0; i++){
                x=n;
                n=n/2;
                m=x%2;

                if(m==1){
                    s[i]=49;
                }
                else if(m==0){
                    s[i]=48;
                }
            }
            s[i]='\0';
            count=0;

            for(i=0, j=strlen(s)-1; i<strlen(s), j>=0;j--,i++){
                if(s[i]=='1'){
                    count++;
                }
                r[j]=s[i];
            }
            r[i]='\0';
            if(count%2!=0)
            printf("odd\n");
            else
            printf("even\n");
    }
    return 0;
}
