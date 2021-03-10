class Solution {
public:
    vector<vector<int>>res;
    vector<int>help(int numRows){
        if(numRows==1) {
            vector<int>temp;
            temp.push_back(1);
            res.push_back(temp);
            return temp;
        }
        
        vector<int>temp;
        vector<int>prev=help(numRows-1);
        
        temp.push_back(1);
        for(int i=1;i<prev.size();i++){
            temp.push_back(prev[i-1]+prev[i]);
        }
        temp.push_back(1);
        
        res.push_back(temp);
        
        return temp;
    }
    vector<vector<int>> generate(int numRows) {        
        help(numRows);
        
        return res;
    }
};