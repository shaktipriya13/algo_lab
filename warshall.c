#include <stdio.h>
#define v 4

void print(int dist[v][v])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (dist[i][j] == 99)
            {
                printf("INF");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void warshalls(int dist[v][v])
{
    int i, j, k;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            for (k = 0; k < v; k++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    print(dist);
}

int main()
{
    int graph[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = i; j < v; j++)
        {
            if (j == i)
            {
                graph[i][j] = 0;
            }
            else
            {
                printf("enter distance between vertex %d and vertex %d, give 99 for no edge ", i, j);
                scanf("%d", &graph[i][j]);
            }
        }
    }

    for (int i = v - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            graph[i][j] = 0;
        }
    }
    warshalls(graph);
    return 0;
}
