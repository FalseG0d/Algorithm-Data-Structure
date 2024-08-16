class Solution {
public:
    void dfs(int curr, int& N, vector<bool>& visited, vector<vector<int>>& isConnected) {
        if(visited[curr]) return;
        visited[curr] = true;

        for(int i=0;i<N;i++) {
            if(isConnected[curr][i] == 1 && !visited[i]) dfs(i, N, visited, isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<bool>visited(N, false);
        int count = 0;

        for(int i=0;i<N;i++) {
            if(visited[i]) continue;

            count++;
            dfs(i, N, visited, isConnected);
        }

        return count;
    }
};