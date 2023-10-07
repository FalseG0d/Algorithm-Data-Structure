class Solution {
public:    
    int maxArea(vector<int>& height) {
        int lm {0};
        int rm = height.size()-1;
        int maxArea {0};

        while (lm < rm) {
            maxArea = std::max(maxArea, std::min(height[lm], height[rm]) * (rm - lm));

            (height[lm] <= height[rm]) ? lm++ : rm--;
        }
        
        return maxArea;
    }
};