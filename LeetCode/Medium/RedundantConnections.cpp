class UnionFind {
    vector<int>parent;
    vector<int>rank;

    public:

    UnionFind(int N) {
        for(int i=0;i<N;i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int findParent(int node){
        while(node != parent[node]){
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    int merge(int node1, int node2) {
        int par1 = findParent(node1);
        int par2 = findParent(node2);

        if(par1 == par2) {
            // Already Merged
            return 1;
        }
        
        if(rank[par1] > rank[par2]) {
            parent[par2] = par1;
            rank[par1] += rank[par2];
        } else {
            parent[par1] = par2;
            rank[par2] += rank[par1];
        }

        return 0;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int N = edges.size();
        UnionFind* uni = new UnionFind(N);

        for(vector<int>edge: edges) {
            int chk = uni->merge(edge[0]-1, edge[1]-1);

            if(chk) {
                res = edge;
                return res;
            }
        }

        return edges[N-1];
    }
};