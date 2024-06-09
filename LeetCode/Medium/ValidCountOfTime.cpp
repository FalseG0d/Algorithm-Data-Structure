class Solution {
public:
    int getValidCountOfHH(string hh) {
        int res = 0;
        int idx = 0;

        for(char ch : hh) {
            if(ch == '?') break;
            idx++;
        }

        for(int i=0;i<10;i++) {
            hh[idx] = '0' + i;

            if(hh <= "23") res++;
        }

        return res;

    }
    int getValidCountOfMM(string mm) {
        int res = 0;
        int idx = 0;

        for(char ch : mm) {
            if(ch == '?') break;
            idx++;
        }

        for(int i=0;i<10;i++) {
            mm[idx] = '0' + i;

            if(mm <= "59") res++;
        }

        return res;

    }
    int countTime(string time) {
        string hh = time.substr(0, 2);
        string mm = time.substr(3);

        int endPtr = 1;

        int countWildHH = 0;
        int countWildMM = 0;

        for(int i=0;i<2;i++) {
            if(hh[i] == '?') countWildHH++;
        }

        for(int i=0;i<2;i++) {
            if(mm[i] == '?') countWildMM++;
        }

        if(countWildHH < 1) countWildHH = 1;
        else if(countWildHH < 2) countWildHH = getValidCountOfHH(hh);
        else countWildHH = 24;

        if(countWildMM < 1) countWildMM = 1;
        else if(countWildMM < 2) countWildMM = getValidCountOfMM(mm);
        else countWildMM = 60;

        return countWildHH * countWildMM;
    }
};