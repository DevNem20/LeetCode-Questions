class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> mpp;

       

        for(int i = 0; i<n; i++) {
            int moreNeeded = target - nums[i];
            if(mpp.count(moreNeeded)) return {mpp[moreNeeded], i};
            mpp[nums[i]] = i;
        }
        return {-1,-1};

    }
};