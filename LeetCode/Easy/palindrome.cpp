class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        
        vector<int>v;
        int len=0;
        
        while(x>0){
            len++;
            v.push_back(x%10);
            x/=10;
        }
        
        for(int i=0;i<len/2;i++){
            if(v[i]!=v[len-i-1])return false;
        }
        
        return true;
    }
};