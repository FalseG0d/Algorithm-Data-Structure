class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph, unordered_map<string, bool>& visited, string src, string& dst) {
        if(visited[src]) return -1;
        
        visited[src] = true;
        
        for(pair<string, double> adj : graph[src]) {
            if(adj.first == dst) return adj.second;
            else {
                double chk = dfs(graph, visited, adj.first, dst);

                if(chk != -1) return adj.second * chk;
            }
        }

        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>>graph;
        int N = equations.size();

        for(int i=0;i<N;i++) {
            graph[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            graph[equations[i][1]].push_back(make_pair(equations[i][0], 1 / values[i]));
        }


        // for(auto itr=graph.begin();itr!=graph.end();++itr) {
        //     cout<<itr->first<<"-> ";
        //     for(pair<string, double> adj : itr->second) cout<<"{"<<adj.first<<", "<<adj.second<<"} ";
        //     cout<<"\n";
        // }

        vector<double> res;

        for(vector<string> query : queries) {
            string src = query[0];
            string dst = query[1];

            unordered_map<string, bool>visited;

            if(src == dst && graph[src].size() > 0) res.push_back(1);
            else res.push_back(dfs(graph, visited, src, dst));
        }

        return res;
    }
};