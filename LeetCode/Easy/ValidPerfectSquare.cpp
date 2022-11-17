class Solution {
public:
    bool isPerfectSquare(int num) {
        int beg = 1;
        int end = num;
        
        while(beg <= end){
            int mid = beg + (end - beg) / 2;
            
            if(mid == num / mid && num % mid == 0) return true;
            else if(mid < num / mid) beg = mid + 1;
            else end = mid - 1;
        }
        
        return false;
    }
};