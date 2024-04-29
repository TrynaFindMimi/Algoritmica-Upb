#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODES = 100;

vector<int> graph[MAX_NODES];
bool visited[MAX_NODES];

void dfs(int node) {
    visited[node] = true;
    cout << "Visitando nodo: " << node << endl;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    fill(visited, visited + numNodes, false);
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cout << "Recorrido DFS del grafo:" << endl;
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    return 0;
}
