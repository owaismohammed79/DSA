class Solution {
  private:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, result);
            }
        }
    }

  public:
    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj(V);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        vector<int> result;
        dfs(0, adj, visited, result);
        return result;
    }

    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj(V);
        for(const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        vector<int> result;
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};