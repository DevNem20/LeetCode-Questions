class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> mpp(101, -1);

        int sum = 0;
        int maxNeg = INT_MIN;

        for(int &num: nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            }
            else {
                if(mpp[num] == -1) {
                    sum += num;
                    mpp[num] = 1;
                }
            }
        }
        return sum == 0 ? maxNeg : sum;
    }
};