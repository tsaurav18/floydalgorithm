#include <stdio.h>

#define V 6    // Number of vertices in the graph

#define IN 999

void path(int dist[][V]);  //prototype of functions
void floyd2(int graph[][V]);
void path_find(int q, int r);

 int p[V][V];  //global 2d array for path
void floyd2(int graph[][V])
{
    int dist[V][V];
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
             p[i][j] = 0;
            dist[i][j] = graph[i][j];
        }
    for (int k = 0; k < V; k++)     // this loop do help to make 8 matrixs
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    p[i][j] = k;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                
                 printf("%4d",dist[i][j]);
            }
            printf("\n");
        }
        if(k<5){  //for correct numbering for D(1...6)
        printf("D(%d):\n",k+2);
            continue;
        }
    }
    path(dist);
//     for(int m=0;m<V;m++){
//         for(int n=0;n<V;n++){
//             printf("%4d",dist[m][n]);
//         }
//         printf("\n");
//     }
}

void path_find(int q, int r) {
    if (p[q][r] != 0) {
        path_find(q, p[q][r]);
        printf("최단경로(P): v%d", p[q][r]);
        path_find(p[q][r], r);
    }
   
}

void path(int dist[][V])
{
    printf("\nmatrix shows the shortest distances"
        " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == IN)
                printf("%5s", "IN");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }
     
}
int main()
{
    int graph[V][V] = { {0, IN,  IN, 1,  6,   2},
                        {5,  0,  12, IN, IN, IN},
                        {IN, 15,  0,  1, IN,  7},
                        {IN, IN, IN,  0,  8,  4},
                        {10, IN, IN,  6,  0, 11},
                        {IN, 10,  3,  2, IN,  0},
    };
    printf("최단거리(D): D(1):\n");
    floyd2(graph);
     printf("\n");
     path_find(4,5);
     
    printf("\n\n");
    
    return 0;
}
