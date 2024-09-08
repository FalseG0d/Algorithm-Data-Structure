class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int holdFive = 0;
        int holdTen = 0;
        int holdTwenty = 0;

        for(int bill: bills) {
            if(bill == 5) {
                holdFive++;
            } else if(bill == 10) {
                if(holdFive >= 1) {
                    holdFive--;
                    holdTen++;
                } else {
                    return false;
                }
            } else {
                if(holdTen >= 1 && holdFive >= 1) {
                    holdTen--;
                    holdFive--;
                    holdTwenty++;
                } else if(holdFive >= 3) {
                    holdFive -= 3;
                    holdTwenty++;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};