class Solution {
public:
    int removeElement(vector<int>&v,int x){
    vector<int>temp=v;
    v.clear();
    
    for(int i=0;i<temp.size();i++){
        if(temp[i]!=x)v.push_back(temp[i]);
    }
    
    return v.size();
    }
};