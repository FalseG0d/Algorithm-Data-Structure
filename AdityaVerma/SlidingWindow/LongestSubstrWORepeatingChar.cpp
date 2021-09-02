class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.length();
        
        int beg = 0;
        int end = 0;
        
        int map[256];
        memset(map,0,sizeof(map));
        
        int res = 0;
        
        while(end < N){
            int index = s[end];
            map[index]++;
            
            while(map[index] > 1){
                map[s[beg]]--;
                beg++;
            }
            
            res = max(res,end - beg + 1);
            
            end++;
        }
        
        return res;
    }
};