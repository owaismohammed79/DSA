struct DSU {
    vector<int> parent, sz;
    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0); //fills parent with 0, 1, ..., n-1
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]); //path compression
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false; //already connected
        if(sz[a] < sz[b]) swap(a, b); //union by size
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

class Solution {
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        DSU dsu(V);
        int ans = V;
        for(auto& v: edges){
            if(dsu.unite(v[0], v[1])) ans--;;
        }
        return ans;
    }
};