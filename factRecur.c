//----- FACTORIAL OF A NUMBER USING RECURSION -----------

#include<stdio.h>

long long int fact(int n) {
    if(n==0 || n==1) return 1;
    else return n*fact(n-1);
}

int main() {
    int n;
    printf("\nEnter A Number : ");
    scanf("%d",&n);
    printf("\n%d! = %d\n\n",n,fact(n));
    return 0;
}
