#include <stdio.h>

int graph[10][10];
int visited[10];
int n;

/* DFS */
void DFS(int v)
{
    int i;

    printf("%d ", v);
    visited[v] = 1;

    for(i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

/* BFS */
void BFS(int start)
{
    int queue[10];
    int front = 0, rear = 0;
    int visitedBFS[10] = {0};
    int i, v;

    queue[rear++] = start;
    visitedBFS[start] = 1;

    while(front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && visitedBFS[i] == 0)
            {
                queue[rear++] = i;
                visitedBFS[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* DFS */
    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    /* BFS */
    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
