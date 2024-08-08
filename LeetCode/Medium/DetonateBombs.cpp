class Solution {
public:
    int bfs(vector<vector<int>>&graph, vector<bool>&visited, int src) {
        queue<int>que;
        que.push(src);
        int res = 0;

        while(!que.empty()) {
            int N = que.size();

            for(int i=0;i<N;i++) {
                int front = que.front();
                que.pop();

                if(visited[front]) continue;
                visited[front] = true;
                res++;

                for(int adj : graph[front]) que.push(adj);
            }
        }

        return res;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int N = bombs.size();
        vector<vector<int>>graph(N);

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(i == j) continue;

                double x = bombs[i][0] - bombs[j][0];
                double y = bombs[i][1] - bombs[j][1];
                double r = bombs[i][2];

                if(x * x + y * y <= r * r) {
                    graph[i].push_back(j);
                }
            }
        }

        // for(int i=0;i<N;i++) {
        //     cout<<i<<": ";
        //     for(int ele : graph[i]) cout<<ele<<" ";
        //     cout<<"\n";
        // }

        int res = 0;
        
        for(int i=0;i<N;i++) {
            vector<bool>visited(N, false);
            res = max(bfs(graph, visited, i), res);
        }

        return res;
    }
};