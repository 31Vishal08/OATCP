#include <bits/stdc++.h>
#define MAX_VERTICES 100 // Maximum number of vertices in the graph
using namespace std;
using namespace std::chrono;

// Breadth-First Search to find an augmenting path
bool find_augmenting_path(int residual_graph[MAX_VERTICES][MAX_VERTICES], int source, int sink, int parent[]) {
    bool visited[MAX_VERTICES];
    memset(visited, 0, sizeof(visited));
    queue<int> bfs_queue;
    bfs_queue.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!bfs_queue.empty()) {
        int current = bfs_queue.front();
        bfs_queue.pop();
        for (int adjacent = 0; adjacent < MAX_VERTICES; adjacent++) {
            if (!visited[adjacent] && residual_graph[current][adjacent] > 0) {
                if (adjacent == sink) {
                    parent[adjacent] = current;
                    return true;
                }
                bfs_queue.push(adjacent);
                parent[adjacent] = current;
                visited[adjacent] = true;
            }
        }
    }
    return false;
}

// Ford-Fulkerson algorithm to find the maximum flow
int ford_fulkerson(int graph[MAX_VERTICES][MAX_VERTICES], int source, int sink) {
    int residual_graph[MAX_VERTICES][MAX_VERTICES];
    // Initialize the residual graph with the original capacities
    for (int i = 0; i < MAX_VERTICES; i++)
        for (int j = 0; j < MAX_VERTICES; j++)
            residual_graph[i][j] = graph[i][j];

    int parent[MAX_VERTICES]; // Array to store the augmenting path
    int max_flow = 0;

    auto start_time = high_resolution_clock::now();
    // While there is an augmenting path from source to sink
    while (find_augmenting_path(residual_graph, source, sink, parent)) {
        int path_flow = INT_MAX;
        // Find the minimum capacity in the augmenting path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residual_graph[u][v]);
        }
        // Update the residual graph based on the path flow
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual_graph[u][v] -= path_flow;
            residual_graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    
    return max_flow;
}

int main() {
    int num_vertices, source_node, sink_node;
    cin >> num_vertices;
    cin >> source_node >> sink_node;

    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize the graph with zero capacity
    int start_node, end_node, edge_capacity;
    while (true) {
        cin >> start_node;
        if (start_node == -1) break;
        cin >> end_node >> edge_capacity;
        graph[start_node][end_node] = edge_capacity; // Assign capacity to the edge
    }

    int max_flow = ford_fulkerson(graph, source_node, sink_node); // Find the maximum flow
    cout << "Maximum Flow: " << max_flow << endl;

    return 0;
}