class Solution {
public:
    string help(vector<string>& nums, string str, int n) {
        if(n == 0) {
            return std::find(nums.begin(), nums.end(), str) != nums.end() ? "" : str;
        }

        string zer = help(nums, str + "0", n-1);
        if(zer.length() > 0) return zer;
        string one = help(nums, str + "1", n-1);
        return one;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int N = nums.size();

        return help(nums, "", N);
    }
};