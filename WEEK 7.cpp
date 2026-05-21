Dijkstra’s Algorithm

#include <iostream>
#include <climits>
using namespace std;

int main() {

    int v;

    cin >> v;

    int graph[100][100];

    for(int i = 0; i < v; i++) {

        for(int j = 0; j < v; j++) {

            cin >> graph[i][j];
        }
    }

    int src;

    cin >> src;

    int dist[100];

    bool visited[100] = {false};

    for(int i = 0; i < v; i++) {

        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for(int count = 0; count < v - 1; count++) {

        int u = -1;

        int minDist = INT_MAX;

        for(int i = 0; i < v; i++) {

            if(!visited[i] && dist[i] < minDist) {

                minDist = dist[i];

                u = i;
            }
        }

        visited[u] = true;

        for(int i = 0; i < v; i++) {

            if(graph[u][i] &&
               !visited[i] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][i] < dist[i]) {

                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    cout << "Vertex Distance\n";

    for(int i = 0; i < v; i++) {

        cout << i << " " << dist[i] << endl;
    }

    return 0;
}

Bellman-Ford Algorithm
#include <iostream>
#include <climits>
using namespace std;

struct Edge {

    int src, dest, weight;
};

int main() {

    int V, E;

    cin >> V >> E;

    Edge edges[E];

    for(int i = 0; i < E; i++) {

        cin >> edges[i].src
            >> edges[i].dest
            >> edges[i].weight;
    }

    int source;

    cin >> source;

    int dist[V];

    for(int i = 0; i < V; i++) {

        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    for(int i = 1; i <= V - 1; i++) {

        for(int j = 0; j < E; j++) {

            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(dist[u] != INT_MAX &&
               dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "Vertex Distance\n";

    for(int i = 0; i < V; i++) {

        cout << i << " " << dist[i] << endl;
    }

    return 0;
}

Shortest Path with Exactly K Edges
#include <iostream>
#include <climits>
using namespace std;

#define INF 99999

int shortestPath(int graph[100][100],
                 int u,
                 int v,
                 int k,
                 int V) {

    if(k == 0 && u == v)
        return 0;

    if(k == 1 && graph[u][v] != INF)
        return graph[u][v];

    if(k <= 0)
        return INF;

    int res = INF;

    for(int i = 0; i < V; i++) {

        if(graph[u][i] != INF && u != i && v != i) {

            int rec = shortestPath(graph,
                                   i,
                                   v,
                                   k - 1,
                                   V);

            if(rec != INF) {

                res = min(res,
                          graph[u][i] + rec);
            }
        }
    }

    return res;
}

int main() {

    int V;

    cin >> V;

    int graph[100][100];

    for(int i = 0; i < V; i++) {

        for(int j = 0; j < V; j++) {

            cin >> graph[i][j];

            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int src, dest;

    cin >> src >> dest;

    int k;

    cin >> k;

    int ans = shortestPath(graph,
                           src,
                           dest,
                           k,
                           V);

    if(ans == INF)
        cout << "No path of length "
             << k
             << " is available";

    else
        cout << "Weight of shortest path from ("
             << src
             << ","
             << dest
             << ") with "
             << k
             << " edges : "
             << ans;

    return 0;
}
