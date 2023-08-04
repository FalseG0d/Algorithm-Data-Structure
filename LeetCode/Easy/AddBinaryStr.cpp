class Solution {
public:
    string addBinary(string a, string b) {
        if(b.length() > a.length()) {
            string temp = a;
            a = b;
            b = temp;
        }

        while(b.length() < a.length()) {
            b = ("0" + b);
        }

        // cout<<a<<" "<<b;

        string ans = "";

        int res = 0;
        int carry = 0;

        for(int i=a.length()-1; i>=0; i--) {
            int a1 = a[i] - 48;
            int b1 = b[i] - 48;

            res = a1 + b1 + carry;
            carry = res / 2;
            res = res % 2;

            ans = to_string(res) + ans;
        }

        if(carry > 0) {
            ans = to_string(carry) + ans;
        }

        return ans;
    }
};