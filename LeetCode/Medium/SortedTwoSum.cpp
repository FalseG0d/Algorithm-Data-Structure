class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res(2);
        int N = numbers.size();

        for(int i=0;i<N-1;i++) {
            int beg = i+1;
            int end = N-1;

            int key = target - numbers[i];
            res[0] = i+1;
            res[1] = -1;

            while(beg <=end) {
                int mid = beg + (end - beg) / 2;

                if(numbers[mid] == key) {
                    res[1] = mid+1;
                    break;
                } else if(numbers[mid] > key) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            }

            if(res[1] != -1) break;
        }

        return res;
    }
};