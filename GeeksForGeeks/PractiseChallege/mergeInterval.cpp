class Solution {
public:
    static bool compareIntervals(vector<int>a,vector<int>b){
        return a[0]*10+a[1]<b[0]*10+b[1];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        
        sort(intervals.begin(),intervals.end(),compareIntervals);
        
        for(int i=0;i<intervals.size();i++){
            int min=intervals[i][0];
            int max=intervals[i][1];
            
            for(int j=i;j<intervals.size();j++){
                if(intervals[j][0]<=max&&intervals[j][1]>=min){
                    if(min>=intervals[j][0]||min>=intervals[j][1]){
                        min=intervals[j][0]<intervals[j][1]?intervals[j][0]:intervals[j][1];
                    }
                    if(max<=intervals[j][0]||max<=intervals[j][1]){
                        max=intervals[j][0]>intervals[j][1]?intervals[j][0]:intervals[j][1];
                    }
                    i=j;
                }
            }
            
            vector<int>row;
            row.push_back(min);
            row.push_back(max);
            ret.push_back(row);
        }
        return ret;
    }
};