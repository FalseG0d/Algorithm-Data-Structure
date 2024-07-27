class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& graph, vector<int>& canComplete) {
        if(canComplete[curr] != -1) return canComplete[curr];

        canComplete[curr] = false;
        bool res = true;

        for(int ele : graph[curr]) {
            res = res && dfs(ele, graph, canComplete);

            if(!res) break;
        }

        canComplete[curr] = res;

        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        vector<vector<int>> prerequisites(numCourses);

        for(vector<int>v : graph) {
            prerequisites[v[0]].push_back(v[1]);
        }

        vector<int>canComplete(numCourses, -1);

        for(int i=0;i<numCourses;i++) {
            if(canComplete[i] == -1) {
                bool res = dfs(i, prerequisites, canComplete);

                if(!res) return false;
            } else if(canComplete[i]) {
                continue;
            } else if(!canComplete[i]){
                return false;
            }
        }

        return true;
    }
};