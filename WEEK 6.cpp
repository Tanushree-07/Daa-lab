Path Exists in Graph using DFS
#include <iostream>
using namespace std;

bool visited[100];

void dfs(int graph[100][100], int v, int src) {

    visited[src] = true;

    for(int i = 0; i < v; i++) {

        if(graph[src][i] == 1 && !visited[i]) {

            dfs(graph, v, i);
        }
    }
}

int main() {

    int v;

    cin >> v;

    int graph[100][100];

    for(int i = 0; i < v; i++) {

        for(int j = 0; j < v; j++) {

            cin >> graph[i][j];
        }
    }

    int src, dest;

    cin >> src >> dest;

    dfs(graph, v, src);

    if(visited[dest])
        cout << "Yes Path Exists";

    else
        cout << "No Such Path Exists";

    return 0;
}

Check Bipartite Graph using BFS
#include <iostream>
#include <queue>
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

    int color[100];

    for(int i = 0; i < v; i++) {
        color[i] = -1;
    }

    queue<int> q;

    color[0] = 0;

    q.push(0);

    bool bipartite = true;

    while(!q.empty()) {

        int u = q.front();

        q.pop();

        for(int i = 0; i < v; i++) {

            if(graph[u][i]) {

                if(color[i] == -1) {

                    color[i] = 1 - color[u];

                    q.push(i);
                }

                else if(color[i] == color[u]) {

                    bipartite = false;
                }
            }
        }
    }

    if(bipartite)
        cout << "Yes Bipartite";

    else
        cout << "Not Bipartite";

    return 0;
}

Cycle Detection in Directed Graph
#include <iostream>
using namespace std;

bool visited[100];
bool recStack[100];

bool dfs(int graph[100][100], int v, int node) {

    visited[node] = true;

    recStack[node] = true;

    for(int i = 0; i < v; i++) {

        if(graph[node][i]) {

            if(!visited[i]) {

                if(dfs(graph, v, i))
                    return true;
            }

            else if(recStack[i]) {

                return true;
            }
        }
    }

    recStack[node] = false;

    return false;
}

int main() {

    int v;

    cin >> v;

    int graph[100][100];

    for(int i = 0; i < v; i++) {

        for(int j = 0; j < v; j++) {

            cin >> graph[i][j];
        }
    }

    bool cycle = false;

    for(int i = 0; i < v; i++) {

        if(!visited[i]) {

            if(dfs(graph, v, i)) {

                cycle = true;

                break;
            }
        }
    }

    if(cycle)
        cout << "Yes Cycle Exists";

    else
        cout << "No Cycle Exists";

    return 0;
}
