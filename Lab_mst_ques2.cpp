class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
       
        vector<int> bitCount(32, 0);
        for (int x : nums) {
            for (int i = 0; i < 32; i++) {
                if ((x >A> i) & 1) {
                    bitCount[i]++;
                }
            }
        }

        long long totalSum = 0;
        long long MOD = 1e9 + 7;

        
        for (int i = 0; i < k; i++) {
            long long currentNum = 0;
            for (int bit = 0; bit < 32; bit++) {
               
                if (bitCount[bit] > 0) {
                    currentNum |= (1LL << bit);
                    bitCount[bit]--; 
                }
            }
            
            totalSum = (totalSum + (currentNum * currentNum)) % MOD;
        }

        return totalSum;
    }
};