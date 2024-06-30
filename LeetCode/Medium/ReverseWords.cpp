class Solution {
public:
    void reverseWords(vector<char>& str) {
        int spaceCount = 0;
        int N = str.size();

        for(char ch : str) {
            if(ch == ' ') spaceCount++;
        }

        if(spaceCount == 0) return;

        reverse(str.begin(), str.end());
        int prev = 0;
        
        for(int i=0;i<N;i++) {
            if(str[i] == ' ') {
                reverse(str.begin() + prev, str.begin() + i);
                
                prev = i + 1;
            }
        }

        reverse(str.begin() + prev, str.begin() + N);
    }
};