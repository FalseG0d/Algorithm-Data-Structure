/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        unordered_map<Node*, Node*>mp;

        queue<Node*>que;
        que.push(node);

        while(!que.empty()) {
            Node*front = que.front();
            que.pop();

            if(mp[front]) continue;

            Node*curr = new Node();
            curr->val = front->val;
            curr->neighbors = {};

            mp[front] = curr;

            for(Node*adj: front->neighbors) {
                if(mp[adj]) {
                    curr->neighbors.push_back(mp[adj]);
                    mp[adj]->neighbors.push_back(curr);
                } else {
                    que.push(adj);
                }
            }
        }

        return mp[node];
    }
};