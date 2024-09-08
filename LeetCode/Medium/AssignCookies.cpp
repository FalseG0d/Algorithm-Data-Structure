class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int G = g.size();
        int S = s.size();

        int itrS = 0;
        int itrG = 0;

        int count = 0;

        while(itrS < S && itrG < G) {
            if(s[itrS] >= g[itrG]) {
                count++;

                itrS++;
                itrG++;
            } else {
                itrS++;
            }
        }

        return count;
    }
};