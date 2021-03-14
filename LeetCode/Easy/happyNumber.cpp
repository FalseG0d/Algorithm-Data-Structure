class Solution {
public:
    bool isHappy(int n) {
        map<int,int>mp;
        int res,temp;
        
        while(true){
            if(n==1)break;
            if(mp[n]>0)return false;
            
            mp[n]++;
            
            res=0;
            while(n>0){
                temp=n%10;
                n/=10;
                
                res+=(temp*temp);
            }
            n=res;
            // cout<<n<<" ";
        }
        
        return true;
    }
};