//---------------- FIBONACCI USING RECURSION ------------------------

#include<stdio.h>

int lookUpTable[1000];
long long int fibo(long long int n);

int main() {
    int n;
    printf("\nWhich Fibonacci Number Do You Want To Calculate ?\n");
    scanf("%d",&n);
    printf("\n%dth fibonacci term is = %d\n\n",n,fibo(n));
    return 0;
}

long long int fibo(long long int n) {
    lookUpTable[0] = 0;
    lookUpTable[1] = 1;
    if(lookUpTable[n] == 0 && n>=2) {
        lookUpTable[n] = fibo(n-1) + fibo(n-2);
    }
    return lookUpTable[n];
}
