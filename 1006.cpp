#include<bits/stdc++.h>
using namespace std;
#define mod 10000007
long long int a, b, c, d, e, f;
long long int arr[100000];
long long int fn(long long int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(arr[n]!=-1) return arr[n];
    else
    {
        arr[n]= fn(n-1)%mod + fn(n-2)%mod + fn(n-3)%mod + fn(n-4)%mod + fn(n-5)%mod + fn(n-6)%mod;
        return arr[n];
    }
}
int main() {
    long long int i, n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {

        for(i=0; i<=10000; i++)
        arr[i]= -1;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n) % mod);
    }
    return 0;
}
