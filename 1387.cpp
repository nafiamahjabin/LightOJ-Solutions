#include<bits/stdc++.h>
using namespace std;
int main(){
    char d[100]="donate", b[100]="report", a[100];
    int t, cs=1;
    cin>>t;
    while(t--)
    {
        printf("Case %d:\n", cs++);
        int m, sum=0,c, c1, i, n;
        scanf("%d", &n);
        for(i=0; i<n; i++){
        scanf("%s", a);
        c=strcmp(a, d);

        if(c==0){
        scanf("%d", &m);
        sum= sum+m;
        }
         c1=strcmp(a, b);
          if(c1==0){
        printf("%d\n", sum);
          }
        }
    }
    return 0;

}
