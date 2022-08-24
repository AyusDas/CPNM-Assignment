#include<stdio.h>
#include<stdlib.h>

struct Matrix {
    int rows;
    int cols;
    int **M;
};

int main() {
    struct Matrix A,B,res;
    printf("\n---------Enter order of 1st Matrix---------\n");
    printf("Rows : ");
    scanf("%d",&A.rows);
    printf("Columns : ");
    scanf("%d",&A.cols);
    A.M = (int**)malloc((A.rows)*sizeof(int*));
    for (int i = 0; i < (A.rows); i++)
        A.M[i] = (int*)malloc((A.cols) * sizeof(int));
    printf("Enter elements of 1st Matrix :\n");
    for(int i=0; i<A.rows; i++) {
        for(int j=0; j<A.cols; j++)
            scanf("%d",&A.M[i][j]);
    }
    printf("\n\n---------Enter order of 2nd Matrix---------\n");
    printf("Rows : ");
    scanf("%d",&B.rows);
    printf("Columns : ");
    scanf("%d",&B.cols);
    B.M = (int**)malloc((B.rows)*sizeof(int*));
    for (int i = 0; i < (B.rows); i++)
        B.M[i] = (int*)malloc((B.cols) * sizeof(int));
    printf("Enter elements of 2nd Matrix :\n");
    for(int i=0; i<B.rows; i++) {
        for(int j=0; j<B.cols; j++)
            scanf("%d",&B.M[i][j]);
    }
    if(A.cols == B.rows) {
        res.rows = A.rows;
        res.cols = B.cols;
        res.M = (int**)malloc((res.rows)*sizeof(int*));
        for (int i = 0; i < (res.rows); i++)
            res.M[i] = (int*)malloc((res.cols) * sizeof(int));
        for(int i=0; i<res.rows; i++) {
            for(int j=0; j<res.cols; j++) {
                res.M[i][j] = 0;
                for(int k=0; k<res.rows; k++)
                    res.M[i][j] += A.M[i][k] * B.M[k][j];
            }
        }
        printf("\n\n_____ MATRIX ______\n\n");
        for (int i = 0; i < res.rows; i++) {
            for (int j = 0; j < res.cols; j++)
                printf("%d\t", res.M[i][j]);
            printf("\n");
            }
        printf("___________________\n");
        printf("\n\n");
    }
    else {
        printf("\nMultiplication Not Possible\n");
    }
    return 0;
}
