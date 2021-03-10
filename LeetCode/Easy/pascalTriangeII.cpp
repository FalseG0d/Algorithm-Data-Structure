class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>temp;
        temp.push_back(1);
        
        if(rowIndex==0){
            return temp;
        }
        
        vector<int>prev=getRow(rowIndex-1);
        
        for(int i=1;i<prev.size();i++){
            temp.push_back(prev[i-1]+prev[i]);
        }
        temp.push_back(1);
        
        return temp;
    }
};