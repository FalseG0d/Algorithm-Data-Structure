class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        int N = s.length();
        string res = "";

        // First Row
        for(int i=0;i<N;) {
            res += s[i];
            i += 2 * (numRows - 2) + 2;
        } // cout<<"\n";

        for(int i=1;i<numRows-1;i++) {
            // Iteration for Rows in between
            bool dec = true;

            for(int j=i;j<N;) {
                res += s[j];

                if(dec) j += 2 * (numRows - 2 - i) + 2;
                else j += 2 * (i - 1) + 2;

                dec = !dec;
            } // cout<<"\n";
        }

        // Last Row
        for(int i=numRows-1;i<N;) {
            res += s[i];
            i += 2 * (numRows - 2) + 2;
        } // cout<<"\n";

        return res;
    }
};