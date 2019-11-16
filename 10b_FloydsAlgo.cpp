#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V]);
void floyd(int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

void printSolution(int dist[][V])
{
    cout<<"The following matrix shows the shortest distance between every pair of vertices: \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<"     ";
            else
                cout<<dist[i][j]<<"     ";
        }
        cout<<endl;
    }
}

int main()
{
    int graph[V][V];
    cout<<"Enter weighted graph matrix (-1 for infinity): ";
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        {
            cin>>graph[i][j];
            if(graph[i][j]==-1)
                graph[i][j]=INF;
        }
    floyd(graph);
    return 0;
}
