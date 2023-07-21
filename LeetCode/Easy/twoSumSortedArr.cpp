class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        
        if(target>0){
            for(int i=0;i<n;i++){
                if(numbers[i]>=target){
                    n=i+1;
                    
                    break;
                }
            }
        }
        
        for(int i=0;i<n-1;i++){
            int sum=target-numbers[i];
            
            for(int j=i+1;j<n;j++){
                if(sum==numbers[j]){
                    vector<int>res={i+1,j+1};
                    return res;
                }
            }
        }
        
        vector<int>res;
        
        return res;
    }
};