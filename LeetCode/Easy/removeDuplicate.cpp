class Solution {
public:
    int removeDuplicates(vector<int>&v){
    set<int>s;
    
    for(int i=0;i<v.size();i++)
        s.insert(v[i]);
    
    v.clear();
        
    for(auto itr=s.begin();itr!=s.end();++itr)
        v.push_back(*itr);
    cout<<"\n";
    
    return s.size();
    }
};