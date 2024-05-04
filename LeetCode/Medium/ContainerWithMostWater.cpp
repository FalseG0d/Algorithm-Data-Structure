class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        
        int res = 0;

        int beg = 0;
        int end = N-1;

        while(beg < end) {
            int W = end - beg;
            int H = min(height[end], height[beg]);

            res = max(res, W * H);

            if(height[end] < height[beg]) end--;
            else beg++;
        }

        return res;
    }
};