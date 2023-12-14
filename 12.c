#include<stdio.h>
void merge(int a[], int low ,int high);
void mergesort(int a[], int low ,int mid  ,int high);
void main()
{
    int i,a[20],n;
    printf("how many elements you want to enter:-");
    scanf("%d",&n);
    printf("enter %d elements: ",n);
     for(i=0; i<n; i++)
        scanf("%d",&a[i]);
        merge(a,0,n-1);
        printf("shorted elements is: \t  \n");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
}

void mergesort(int a[], int low ,int mid  ,int high)
{
	int i=low,j=mid+1,k=0,b[20];           
        while((i<=mid)&&(j<=high))
       {
            if(a[i]<a[j])
           {
                b[k++]=a[i++];
	   }
           else
          {
                b[k++]=a[j++];
          }
      }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=high)
    {
        b[k++]=a[j++];
    }
    for(j=low, k=0; j<=high;  j++,k++)
    {
        a[j]=b[k];
    }
}

void merge(int a[],int low ,int high)
{
    int mid;
    if(low<high)
    {
    	mid=(low+high)/2;
		merge(a,low,mid);
        merge(a,mid+1,high);
  		mergesort(a,low,mid,high);
    }

 }

