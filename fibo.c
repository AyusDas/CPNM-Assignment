// Fibonacci using function : 

#include<stdio.h>

void fibo(int n) {
    int a=0, b=1, c;
    printf("0, 1,");
    for(int i=0; i<=n; i++) {
        c = a+b;
        printf(" %d,",c);
        a = b;
        b = c;
    }
    printf("...\n\n\n");
}

int main() {
    int n;
    printf("\n\nhow many terms of fibonacci do you want to print ? ");
    scanf("%d",&n);
    fibo(n);
    return 0;
}
