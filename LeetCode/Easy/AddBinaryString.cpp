class Solution {
public:
    string addBinary(string a, string b) {
        int N1 = a.length();
        int N2 = b.length();

        int carry = 0;
        string res = "";

        while(N1 > 0 && N2 > 0) {
            int sum = (a[N1-1] - '0') + (b[N2-1] - '0') + carry;

            carry = sum / 2;
            res = to_string(sum % 2) + res;

            N1--;
            N2--;
        }

        while(N1 > 0) {
            int sum = a[N1-1] - '0' + carry;

            carry = sum / 2;
            res = to_string(sum % 2) + res;

            N1--;
        }

        while(N2 > 0) {
            int sum = (b[N2-1] - '0') + carry;

            carry = sum / 2;
            res = to_string(sum % 2) + res;

            N2--;
        }

        if(carry > 0) res = to_string(carry) + res;

        return res;
    }
};