class Solution {
public:
    double maxProbability(int N, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> graph(N);

        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(make_pair(succProb[i], edges[i][1]));
            graph[edges[i][1]].push_back(make_pair(succProb[i], edges[i][0]));
        }

        vector<double>prob(N, 0);
        
        priority_queue<pair<double, int>>pq;
        pq.push(make_pair(1, start_node));
        prob[start_node] = 1;

        while(!pq.empty()) {
            pair<double,int>p = pq.top();
            pq.pop();

            for(pair<double, int>adj: graph[p.second]) {
                double nextNodeProb = adj.first * p.first;
                int nextNode = adj.second;

                if(nextNodeProb > prob[nextNode]) {
                    prob[nextNode] = nextNodeProb;
                    pq.push(make_pair(nextNodeProb, nextNode));
                }
            }
        }

        return prob[end_node];
    }
};