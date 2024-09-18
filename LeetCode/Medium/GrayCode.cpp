class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> grey;
        for (int i = 0; i < 1 << n; ++i) {  
            grey.push_back(i ^ (i >> 1));
        }
        return grey;
    }
};