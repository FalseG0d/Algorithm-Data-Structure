class Solution {
public:
    vector<vector<int>> res;
    
    void help(int beg, const int& end, int k, vector<int> temp){        
        if(k == 0){
            res.push_back(temp);
            return;
        }
        
        for(int i=beg;i<=end;i++){
            temp.push_back(i);
            help(i+1,end,k-1,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        help(1, n, k, {});
        
        return res;
    }
};