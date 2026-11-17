
#include <stdio.h>

#define INF 9999

void dijkstra(int a[10][10], int n, int src)
{
    int dist[10], visited[10];
    int i, j, min, u;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (i = 0; i < n; i++)
    {
        min = INF;

        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (a[u][j] != 0 && visited[j] == 0)
            {
                if (dist[u] + a[u][j] < dist[j])
                {
                    dist[j] = dist[u] + a[u][j];
                }
            }
        }
    }

    printf("\nShortest distances:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d to %d = %d\n", src, i, dist[i]);
    }
}

int main()
{
    int a[10][10], n, src, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(a, n, src);

    return 0;
}
0