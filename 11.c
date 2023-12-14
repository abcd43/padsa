/*Assignment no: 11
Title : Write a program to arrange list of students to find out first ten 
toppers from a class using Bubble sort. (refer the student
database given in assignment 10).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
 char name[50];
 float percentage;
};

void bubbleSort(struct Student students[], int n) 
{
int i,j;
for ( i= 0; i < n - 1; ++i) 
{
	for ( j = 0; j < n - i - 1; ++j) 
	{
	if (students[j].percentage < students[j + 1].percentage)
	{
 		struct Student temp = students[j];
 		students[j] = students[j + 1];
 		students[j + 1] = temp;
 	}
 	}
 }
}
int main() 
{
 int n,i;
 printf("Enter the number of students: ");
 scanf("%d", &n);
 struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

 for ( i = 0; i < n; ++i) 
 {
 printf("\nEnter details for student %d:\n", i + 1);
 printf("Name: ");
 scanf("%s", students[i].name);
 printf("Percentage: ");
 scanf("%f", &students[i].percentage);
 }
 
 bubbleSort(students, n);
 printf("\nTop Ten Toppers:\n");
 printf("Rank\tName\t\tPercentage\n");
 for (i = 0; i < (n < 10 ? n : 10); ++i) 
 {
 printf("%d\t%s\t\t%.2f\n", i + 1, students[i].name, students[i].percentage);
 }

 return 0;
}
