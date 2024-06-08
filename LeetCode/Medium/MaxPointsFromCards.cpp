class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int N = cardPoints.size();
        int windowLen = N - k;

        int sum = 0;
        for(int ele : cardPoints) sum += ele;

        int offSet = 0;

        for(int i=0;i<N-k;i++) offSet += cardPoints[i];

        int tempOff = offSet;

        for(int i=0;i<k;i++) {
            tempOff -= cardPoints[i];
            tempOff += cardPoints[N-k+i];

            offSet = min(offSet, tempOff);
        }

        return sum - offSet;
    }
};