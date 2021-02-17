class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        
        for(auto itr=s.begin();itr!=s.end();++itr){
            st.push(*itr);
        }
        
        s.clear();
        
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
    }
};