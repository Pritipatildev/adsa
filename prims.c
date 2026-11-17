
#include <stdio.h>
#define INF 9999

void prim(int a[10][10], int n)
{
    int visited[10] = {0};
    int i, j, min, u = 0, v = 0;
    int cost = 0, count = 0;

    visited[0] = 1;

    printf("\nSelected Edges:\n");

    while (count < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && a[i][j] != 0)
                    {
                        if (a[i][j] < min)
                        {
                            min = a[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        if (min == INF)
        {
            printf("Spanning tree not possible");
            return;
        }

        printf("%d - %d = %d\n", u, v, min);

        cost = cost + min;
        visited[v] = 1;
        count++;
    }

    printf("\nMinimum Cost = %d", cost);
}

int main()
{
    int a[10][10], n, i, j;

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

    prim(a, n);

    return 0;
}
