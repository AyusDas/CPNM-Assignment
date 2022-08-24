//------- MATRIX MULTIPLICATION USING FILE HANDLING ---------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int **A, **B, **res;
    char arraySelectorFlag='A';
    int rows=0,eles=0;
    int rowsForA=0, colsForA=0, rowsForB=0, colsForB=0;
    FILE *fp, *tempf;
    char ch, chf, no[10], func[4],operation;
    fp = fopen("./public/input.json","r");
    if(fp == NULL) {
        printf("\tERROR : Cannot open file");
        return 0;
    }
    else {
        fscanf(fp,"%c",&ch);
        while(!feof(fp)) {
            if(ch == '[') {
                while(ch != ']') {
                    if(ch == '\n') rows++;
                    else if(ch == ',') eles++;
                    fscanf(fp,"%c",&ch);
                }
                if(arraySelectorFlag=='A') {
                    rowsForA = rows+1;
                    colsForA = (eles+1)/(rows+1);
                    A = (int**)malloc((rowsForA)*sizeof(int*));
                    for (int i = 0; i < (rowsForA); i++)
                        A[i] = (int*)malloc((colsForA) * sizeof(int));
                    arraySelectorFlag = 'B';
                }
                else if(arraySelectorFlag == 'B') {
                    rowsForB = rows+1;
                    colsForB = (eles+1)/(rows+1);
                    B = (int**)malloc((rowsForB)*sizeof(int*));
                    for (int i = 0; i < (rowsForB); i++)
                        B[i] = (int*)malloc((colsForB) * sizeof(int));
                    arraySelectorFlag = 'A';
                }
                rows = 0;
                eles = 0;            
            }
            fscanf(fp,"%c",&ch);
        }
    }
    fclose(fp);
    tempf = fopen("./public/input.json","r");
    if(tempf == NULL) {
        printf("\tERROR : Cannot open file");
        return 0;
    }
    else {
        fscanf(tempf,"%c",&chf);
        while(!feof(tempf)) {
            if(chf == '[') {
                int j=0;
                while(chf != ']') { 
                    fscanf(tempf,"%c",&chf);
                    int i=0,k=0;
                    while(chf != ']' && chf != '\n') { 
                        if(chf != ',' && chf != ' ') {
                            no[i] = chf;
                            i++;
                        }
                        if(chf == ',') {
                            no[i] = '\0';
                            if(arraySelectorFlag == 'A') {
                                A[j][k] = atoi(no);
                                i=0;
                                k++;
                                if(k >= colsForA) {
                                    j++;
                                    k=0;
                                }
                            }
                            if(arraySelectorFlag == 'B') {
                                B[j][k] = atoi(no);
                                i=0;
                                k++;
                                if(k >= colsForB) {
                                    j++;
                                    k=0;
                                }
                            }
                        }
                        if(j==rowsForA-1 && k==colsForA-1 && chf!=' ' && arraySelectorFlag=='A') {
                            no[i] = '\0';
                            A[j][k] = atoi(no); 
                        }
                        if(j==rowsForB-1 && k==colsForB-1 && chf!=' ' && arraySelectorFlag=='B') {
                            no[i] = '\0';
                            B[j][k] = atoi(no); 
                        }
                        fscanf(tempf,"%c",&chf);
                    }
                }
                arraySelectorFlag = 'B';
            }
            if(chf == '*') {
                operation = chf;
                fscanf(tempf,"%c",&chf);
                if(chf == 'B') strcpy(func,"A*B");
                else if(chf == 'A') strcpy(func,"B*A");
            }
            fscanf(tempf,"%c",&chf);
        }
    }
    fclose(fp);
    printf("\n\n\n");
    printf("____ MATRIX A _____\n\n");
    for (int i = 0; i < rowsForA; i++) {
		for (int j = 0; j < colsForA; j++)
			printf("%d\t", A[i][j]);
        printf("\n");
    }
    printf("___________________\n");
    printf("\n\n");
    printf("____ MATRIX B _____\n\n");
    for (int i = 0; i < rowsForB; i++) {
		for (int j = 0; j < colsForB; j++)
			printf("%d\t", B[i][j]);
        printf("\n");
    }
    printf("___________________\n");
    printf("\n");
    if(strcmp(func,"A*B")==0) {
        printf("---------- Performing A x B ----------\n\n");
        if(colsForA != rowsForB) {
            printf("--------- ERROR : Multiplication Not Possible ----------");
        }
        else {
            res = (int**)malloc((rowsForA)*sizeof(int*));
            for (int i = 0; i < (rowsForA); i++)
                res[i] = (int*)malloc((colsForB) * sizeof(int));
            for(int i=0; i<rowsForA; i++) {
                for(int j=0; j<colsForB; j++) {
                    res[i][j] = 0;
                    for(int k=0; k<rowsForB; k++)
                        res[i][j] += A[i][k] * B[k][j];
                }
            }
            printf("____ MATRIX R _____\n\n");
            for (int i = 0; i < rowsForA; i++) {
                for (int j = 0; j < colsForB; j++)
                    printf("%d\t", res[i][j]);
                printf("\n");
            }
            printf("___________________\n");
            printf("\n\n");   
        }
    }
    else if(strcmp(func,"B*A")==0) {
        printf("---------- Perfoming B x A -----------\n\n");
        if(colsForB != rowsForA) {
            printf("---------- ERROR : Multiplication Not Possible ----------");
        }
        else {
            res = (int**)malloc((rowsForB)*sizeof(int*));
            for (int i = 0; i < (rowsForB); i++)
                res[i] = (int*)malloc((colsForA) * sizeof(int));
            for(int i=0; i<rowsForB; i++) {
                for(int j=0; j<colsForA; j++) {
                    res[i][j] = 0;
                    for(int k=0; k<rowsForA; k++)
                        res[i][j] += B[i][k] * A[k][j];
                }
            }
            printf("____ MATRIX R _____\n\n");
            for (int i = 0; i < rowsForB; i++) {
                for (int j = 0; j < colsForA; j++)
                    printf("%d\t", res[i][j]);
                printf("\n");
            }
            printf("___________________\n");
            printf("\n\n");
        }
    }
    return 0;
}
