class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        for(int i=0;i<intervals.size()-1;i++){
            int min=intervals[i][0];
            int max=intervals[i][1];
            int j=i+1;
            // for(int j=i+1;j<intervals.size();j++){
                if(intervals[j][0]>max){
                    max=intervals[j][0];
                }
                if(intervals[j][1]>max){
                    max=intervals[j][0];
                }
                if(intervals[j][0]<min){
                    min=intervals[j][0];
                }
                if(intervals[j][1]<min){
                    min=intervals[j][0];
                }
            // }
            vector<int>row;
            row.push_back(min);
            row.push_back(max);
            ret.push_back(row);
        }
        return ret;
    }
};