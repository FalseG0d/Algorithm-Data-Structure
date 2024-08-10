class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n);

        for(int i=0;i<times.size();i++) {
            graph[times[i][0]-1].push_back(make_pair(times[i][2], times[i][1]-1));
        }

        vector<int>delay(n, INT_MAX);
        delay[k-1] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push(make_pair(0, k-1));

        while(!pq.empty()) {
            pair<int,int>curr = pq.top();
            pq.pop();

            for(pair<int,int>next: graph[curr.second]) {
                if(delay[next.second] > curr.first + next.first) {
                    delay[next.second] = curr.first + next.first;
                    pq.push(make_pair(delay[next.second], next.second));
                }
            }
        }

        int res = 0;

        for(int i=0;i<delay.size();i++) res = max(delay[i], res);

        return res == INT_MAX ? -1 : res;
    }
};