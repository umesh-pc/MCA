#include<stdio.h>
#include<stdlib.h>

#define max 10

int queue[max],front=-1,rear=-1;
int visited[max];

void enqueue(int vertex)
{
    if(rear==max-1)
    {
        return;
    }
    if(front==-1)
    {
        front=0;
    }
        queue[++rear]=vertex;
    
}

int dequeue()
    {
        if(front==-1||front>rear)
        {
            return -1;
        }
        return queue[front++];
    }

void bfs(int graph[max][max],int start,int n)
{
    int i;
    enqueue(start);
    visited[start]=1;

    printf(" BFS traversel ");
    
    while (front<=rear)
    {
        int curent=dequeue();
        printf("%d ",curent);

        for(i=0;i<n;i++)
        {
        if(graph[curent][i]==1 && !visited[i])
        {
         enqueue(i);
         visited[i]=1;
        }
        } 
    }
    printf("\n");
}
int main() {
    int n, i, j, start;
    int graph[max][max];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    bfs(graph, start, n);

    return 0;
}