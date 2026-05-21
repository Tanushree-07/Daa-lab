Prim’s Algorithm (Minimum Spanning Tree)
#include <iostream>
#include <climits>
using namespace std;

int main() {

    int V;

    cin >> V;

    int graph[100][100];

    for(int i = 0; i < V; i++) {

        for(int j = 0; j < V; j++) {

            cin >> graph[i][j];
        }
    }

    int key[100];

    bool mst[100];

    for(int i = 0; i < V; i++) {

        key[i] = INT_MAX;

        mst[i] = false;
    }

    key[0] = 0;

    int result = 0;

    for(int count = 0; count < V; count++) {

        int u = -1;

        for(int i = 0; i < V; i++) {

            if(!mst[i] &&
               (u == -1 || key[i] < key[u])) {

                u = i;
            }
        }

        mst[u] = true;

        result += key[u];

        for(int i = 0; i < V; i++) {

            if(graph[u][i] &&
               !mst[i] &&
               graph[u][i] < key[i]) {

                key[i] = graph[u][i];
            }
        }
    }

    cout << "Minimum Spanning Weight: "
         << result;

    return 0;
}

Kruskal’s Algorithm
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {

    int u, v, w;
};

bool compare(Edge a, Edge b) {

    return a.w < b.w;
}

int parent[100];

int find(int x) {

    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {

    parent[find(a)] = find(b);
}

int main() {

    int V, E;

    cin >> V >> E;

    Edge edges[E];

    for(int i = 0; i < E; i++) {

        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    sort(edges, edges + E, compare);

    for(int i = 0; i < V; i++) {

        parent[i] = i;
    }

    int cost = 0;

    for(int i = 0; i < E; i++) {

        int u = edges[i].u;

        int v = edges[i].v;

        if(find(u) != find(v)) {

            Union(u, v);

            cost += edges[i].w;
        }
    }

    cout << "Minimum Spanning Weight: "
         << cost;

    return 0;
}

Maximum Spanning Tree
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {

    int u, v, w;
};

bool compare(Edge a, Edge b) {

    return a.w > b.w;
}

int parent[100];

int find(int x) {

    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {

    parent[find(a)] = find(b);
}

int main() {

    int V, E;

    cin >> V >> E;

    Edge edges[E];

    for(int i = 0; i < E; i++) {

        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    sort(edges, edges + E, compare);

    for(int i = 0; i < V; i++) {

        parent[i] = i;
    }

    int cost = 0;

    for(int i = 0; i < E; i++) {

        int u = edges[i].u;

        int v = edges[i].v;

        if(find(u) != find(v)) {

            Union(u, v);

            cost += edges[i].w;
        }
    }

    cout << "Maximum Spanning Weight: "
         << cost;

    return 0;
}
