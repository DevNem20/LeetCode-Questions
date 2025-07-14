class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> mpp;
        for(int i = 0; i<n; i++) {
            mpp[nums[i]] = i;
        }

        for(int i = 0; i<n; i++) {
            for(int j = i+1; j <n; j++) {
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};
    }
};