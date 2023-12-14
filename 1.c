/*Assignment No 1:
Title: Write a program to represent sparse matrix using array and 
perform simple and fast Transpose.*/


#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ELEMENTS 100

typedef struct
{
    int row;
    int col;
    int value;
} Element;

void simpleTranspose(Element input[], Element output[], int numRows, int numCols) 
{
    int count = 0,i,j;
    output[0].row = numCols;
    output[0].col = numRows;
    output[0].value = input[0].value;

    for (i = 0; i < numCols; i++) {
        for (j = 1; j <= input[0].value; j++) {
            if (input[j].col == i) {
                count++;
                output[count].row = i;
                output[count].col = input[j].row;
                output[count].value = input[j].value;

            }
        }
    }
}


int main() {
    Element input[MAX_ELEMENTS];
    Element simpleTransposed[MAX_ELEMENTS];

    int numRows, numCols, numTerms;

    printf("Enter the number of rows, columns, and non-zero terms: ");
    scanf("%d %d %d", &numRows, &numCols, &numTerms);

    input[0].row = numRows;
    input[0].col = numCols;
    input[0].value = numTerms;
    	int i;

    printf("Enter the elements (row, col, value) of the matrix:\n");
    for (i = 1; i <= numTerms; i++) 
	{
        scanf("%d %d %d", &input[i].row, &input[i].col, &input[i].value);
    }

    simpleTranspose(input, simpleTransposed, numRows, numCols);

    printf("Simple Transpose:\n");
    for (i = 0; i <= simpleTransposed[0].value; i++) 
	{
        printf("%d %d %d\n", simpleTransposed[i].row, simpleTransposed[i].col, simpleTransposed[i].value);
    }
    return 0;
}


/*FastT.c
#include<stdio.h>
int main(){
int A[][3]={{4,4,5},{0,0,8},{0,3,5},{1,2,30},{1,3,26},{3,1,28}};
int t=sizeof(A)/sizeof(int)/3;
int i,j;
for(i=0;i<t;i++){
for(j=0;j<3;j++){
printf("%d ",A[i][j]);
}
printf("\n");
}
int limit=A[0][1],k=0;
int freq[limit],start[limit];
for(i=0;i<limit;i++){
freq[i]=0;
start[i]=0;
}
while(k!=limit){
for(i=0;i<t;i++){
if(k==A[i][1]){
freq[k]+=1;
}
}
k++;
}
printf("\n--------Frequency---------\n");
for(j=0;j<limit;j++){
printf("%d ",freq[j]);
}
printf("\n---------Index------------\n");
if(freq[0]>0)
start[0]=1;
else
start[0]=0;
for(i=1;i<limit;i++){
start[i]=start[i-1]+freq[i-1];
}
for(j=0;j<limit;j++){
printf("%d ",start[j]);
}
int B[t][3];
B[0][0]=A[0][1];
B[0][1]=A[0][0];
B[0][2]=A[0][2];
int in=0;
printf("\n------Fast Transpose-------\n");
int up=1;
for(i=1;i<t;i++){
int temp=A[i][1];
B[start[temp]][0]=temp;
B[start[temp]][1]=A[i][0];
B[start[temp]][2]=A[i][2];
start[temp]+=1;
}
for(i=0;i<t;i++){
for(j=0;j<3;j++){

printf("%d ",B[i][j]);
}
printf("\n");
}
}*/

