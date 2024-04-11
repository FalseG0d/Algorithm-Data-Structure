class Solution {
public:
    int countPrimes(int n) {
        bitset<10000000> bt;
        for(int i = 2; i < n; i++)
        {
            bt.set(i);
        }
        for(int i = 2; i < n; i++)
        {
            if(bt[i])
            {
                for(int j = 2; i * j < n; j++)
                {
                    bt.reset(i * j);
                }
            }
        }
        return bt.count();
    }
};