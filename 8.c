/*Assignment no: 8
Title: Write a program to create graph, use the map of any city as the 
graph. Represent graph using adjacency list/adjacency matrix 
and perform Depth First Search and Breadth First Search.*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct node
{
	int vertex;
	struct node * next;
}NODE;

NODE *list[10];

   typedef struct 
    {
    	int front, rear;
    	int info[MAXSIZE];
    }QUEUE;
    
    void addq(QUEUE *pq, int n)
    {
    	pq->info[++pq->rear] = n;
    }

    void initq(QUEUE *pq)
    {
    	pq->front = pq->rear = -1;
    }


    int removeq(QUEUE *pq)
    {
    	return pq->info[++pq->front];
    }

    int isempty(QUEUE *pq)
    {
    	return (pq->front == pq->rear);
    }

void createmat(int m[10] [10], int n)
{
	int i, j;
	//char ans;
	for(i=0; i<n; i++)
		for(j=0;j<n; j++)
		{
			m[i] [j] = 0;
			if(i != j)
			{
				printf("Is there an edge between %d->%d (1/0) :",i+1, j+1);
				scanf("%d", &m[i][j]);
			}
		}
}

void dismat( int m[10][10], int n)
{
	int i, j;
	printf("\n The Adjacency Matrix is:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		printf("\t%d", m[i] [j]);
		printf("\n");
	}
}

void createlist( int m [10] [10], int n)
{
	int i, j;
	NODE *temp, *nn;
	for(i=0; i<n; i++)
	{
		list[i] = NULL;
		for(j=0; j<n; j++)
		{
			if(m[i][j] == 1)
			{
				nn=(NODE *)malloc(sizeof(NODE));
				nn->vertex=j+1;
				nn->next=NULL;
				if(list[i] == NULL)
					list[i] = temp = nn;
				else
				{
					temp->next=nn;
					temp=nn;
				}	
			}
		}
	}
}

void dislist(int m[10] [10], int n)
{
	NODE *temp;
	int i;
	printf("\n\nThe Adjacency list is:");
	for(i=0; i<n; i++)
	{
		printf("\nv%d->",i+1);
		temp=list[i];
		while(temp)
		{
			printf("v%d ->",temp->vertex);
			temp = temp->next;
		}
		printf("NULL");
	}
}



void dfs(int m[10][10], int n, int v)
{
	int w;
	static int visited[20]={0};
	visited[v]=1;
	printf("v%d ",v+1);
	for(w=0; w<n; w++)
	{
		if((m[v][w] == 1) && (visited[w] == 0))
		dfs(m, n, w);
	}
}	

void bfs(int m[10][10], int n)
{
	int  v, w;
	int visited[20] = {0};
	QUEUE q;
	initq(&q);
	v=0; //starting vertex is 0
	visited[v]=1;
	addq(&q,v);
	while(!isempty(&q))
	{
		v=removeq(&q);
		printf("v%d ",v+1);
		for(w=0; w<n; w++)
			if((m[v][w] == 1) && (visited[w] == 0) )
			{
				addq(&q, w);
				visited[w] = 1;
			}
	}
}

void main()
{
	int m[10][10], n,w;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	
	createmat(m,n);
	dismat(m,n);
	
	
	
	createlist(m,n);
	dislist(m,n);
	
	printf("\n\nThe Depth First Search Traversal  is:\t");
	dfs(m,n,w);
	
	printf("\n\nThe Breadth First Traversal is:\t");
	bfs(m,n);
}
