class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int N1 = num1.length();
        int N2 = num2.length();
        
        vector<int>tmpSum(N1 + N2, 0);

        for(int i=0;i<N1;i++) {
            for(int j=0;j<N2;j++) {
                tmpSum[i + j] = tmpSum[i + j] + (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for(int i=0;i<N1+N2;i++) {
            tmpSum[i] += carry;

            carry = tmpSum[i] / 10;
            tmpSum[i] %= 10;
        }

        reverse(tmpSum.begin(), tmpSum.end());

        int itr = 0;

        while(itr < N1 + N2 && tmpSum[itr] == 0) itr++;

        string res = "";

        for(;itr < N1 + N2; itr++) res += to_string(tmpSum[itr]);

        return res;
    }
};