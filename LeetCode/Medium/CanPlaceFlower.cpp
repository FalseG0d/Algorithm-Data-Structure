class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();

        flowerbed.push_back(0);
        flowerbed.push_back(0);

        N += 2;
        
        for(int i=N-2;i>0;i--) {
            flowerbed[i] = flowerbed[i-1];
        }

        flowerbed[0] = 0;

        // for(int i=0;i<N;i++) cout<<flowerbed[i]<<" ";

        int left = 0;
        int right = 2;

        int sum = 0;

        for(int i=left;i<right;i++) sum += flowerbed[i];

        int count = 0;

        while(right < N) {
            sum += flowerbed[right];
            if(sum == 0) {
                count++;
                sum++;
                flowerbed[left+1] = 1;
                }
            sum -= flowerbed[left];
            
            left++;
            right++;
        }

        return count >= n;
    }
};