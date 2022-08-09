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
    void print(Node*node){
        queue<Node*>que;
        que.push(node);        
        unordered_map<Node*,bool>mp;
        while(!que.empty()){
            Node*temp = que.front();
            que.pop();
            if(mp[temp]) continue;
            cout<<temp->val<<": ";
            for(Node*itr:temp->neighbors){
                cout<<itr->val<<", ";
                if(mp.find(itr) == mp.end()) que.push(itr);
            }
            cout<<"\n";
            mp[temp] = true;
        }
    }
    
    Node* cloneGraph(Node* node) {
        // print(node);
        if(node == NULL) return NULL;
        
        unordered_map<Node*,Node*>mp;
        unordered_map<Node*,bool>visited;
        
        queue<Node*> que;
        que.push(node);
        
        Node*currNew = NULL;
        
        while(!que.empty()){
            Node*curr = que.front();
            que.pop();
            
            if(visited.find(curr) != visited.end()) continue;
            
            
            if(mp.find(curr) != mp.end()) currNew = mp[curr];
            else{
                currNew = new Node(curr->val);
                mp[curr] = currNew;
            }
            
            for(Node*neighbors:curr->neighbors){
                Node*temp = NULL;
                if(mp.find(neighbors) != mp.end()) temp = mp[neighbors];
                else{
                    temp = new Node(neighbors->val);
                    mp[neighbors] = temp;
                }
                
                currNew->neighbors.push_back(temp);
                
                if(visited.find(neighbors) == visited.end()) que.push(neighbors);
            }
            
            
            // curr->val = -1 * curr->val;
            visited[curr] = true;
        }
        
        que.push(currNew);
        visited.clear();
        
        while(!que.empty()){
            Node*temp = que.front();
            que.pop();
            
            if(temp->val == node->val) return temp;
            
            for(Node*itr:temp->neighbors){
                if(visited.find(itr) == visited.end()) que.push(itr);
            }
        }
        
        return currNew;
        // return NULL;
    }
};