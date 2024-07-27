class Solution {
public:
    void dfs(vector<vector<int>>&graph, vector<bool>&visited1, vector<bool>&visited2, stack<int> &st, int src) {
        visited1[src] = visited2[src] = true;

        for(int dest : graph[src]) {
            if(visited1[dest] && visited2[dest]) return;
            if(visited1[dest]) continue;

            dfs(graph, visited1, visited2, st, dest);
        }

        st.push(src);
        visited2[src] = false;
    }

    vector<int> findOrder(int N, vector<vector<int>>& prereq) {
        vector<bool>visited1(N, false);
        vector<bool>visited2(N, false);
        vector<vector<int>>graph(N);

        for(vector<int>edge:prereq) {
            graph[edge[1]].push_back(edge[0]);
        }

        stack<int>st;
        vector<int>res;

        for(int i=0;i<N;i++) {
            if(visited1[i]) continue;
            dfs(graph, visited1, visited2, st, i);
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        if(res.size() != N) return {};

        return res;
    }
};