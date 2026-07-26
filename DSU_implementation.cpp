#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
        vector<int> parent, rank, size;
    public:
        DisjointSet(int n) {
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1, 1);

            for(int i =0; i <=n; i++){
                parent[i] = i;
            }
        }

        int findUParent(int u){
            if(u == parent[u]) return u;
            return parent[u] = findUParent(parent[u]); //Space optimization
        }

        void unionByRank(int u, int v){
            int up_u = findUParent(u);
            int up_v = findUParent(v);

            if(up_u == up_v) return; //Already connected

            if(rank[up_u] > rank[up_v]){
                parent[up_v] = up_u;
            } else if(rank[up_u] < rank[up_v]){
                parent[up_u] = up_v;
            } else {
                parent[up_u] = up_v;
                rank[up_v]++;
            }
        }

        void unionBySize(int u, int v) {
            int up_u = findUParent(u);
            int up_v = findUParent(v);

            if(up_u == up_v) return;

            if(size[up_u] > size[up_v]){
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            } else{
                parent[up_u] = up_v;
                size[up_v] += size[up_u];
            }
        }
};

//These are usually given
vector<int> adjLs;
int v;
