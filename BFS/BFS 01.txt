#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_NODES = 100;

vector<int> graph[MAX_NODES];
bool visited[MAX_NODES];

void bfs(int startNode) {
    fill(visited, visited + MAX_NODES, false);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Visitando nodo: " << current << endl;
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cout << "Recorrido BFS del grafo:" << endl;
    bfs(0);
    return 0;
}
