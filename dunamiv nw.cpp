#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V, timer;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> visited;

    void dfs(int u, int parent) {
        visited[u] = true;
        disc[u] = low[u] = ++timer;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u])
                    cout << u << " - " << v << " is a bridge\n";
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    Graph(int n) {
        V = n;
        adj.resize(V);
        disc.resize(V);
        low.resize(V);
        visited.resize(V, false);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findBridges() {
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i, -1);
    }
};
