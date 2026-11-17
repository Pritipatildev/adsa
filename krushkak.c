
#include <stdio.h>

int parent[10];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void kruskal(int edges[20][3], int n, int e)
{
    int i, j, k, temp;
    int u, v, p1, p2;
    int cost = 0, count = 0;

    // Sort edges by weight
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                for (k = 0; k < 3; k++)
                {
                    temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }

    // Initialize parent
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nSelected Edges:\n");

    // Select edges
    for (i = 0; i < e && count < n - 1; i++)
    {
        u = edges[i][0];
        v = edges[i][1];

        p1 = find(u);
        p2 = find(v);

        if (p1 != p2)
        {
            printf("%d - %d = %d\n", u, v, edges[i][2]);

            cost = cost + edges[i][2];
            parent[p1] = p2;
            count++;
        }
    }

    if (count == n - 1)
        printf("\nMinimum Cost = %d", cost);
    else
        printf("\nSpanning Tree not possible");
}

int main()
{
    int n, e, edges[20][3];
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter source destination and weight:\n");

    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);

    kruskal(edges, n, e);

    return 0;
}
