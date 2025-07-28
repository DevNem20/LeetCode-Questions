class Solution {
public:

    int solve(int idx, int curOr, vector<int>& nums, int maxOr, vector<vector<int>>& t) {
        if(idx == nums.size()) {
            if(curOr == maxOr) return 1;
            else return 0;
        }
        if(t[idx][curOr] != -1) return t[idx][curOr];
        int take = solve(idx + 1, curOr | nums[idx], nums, maxOr, t);
        int notTake  = solve(idx + 1, curOr, nums, maxOr, t);

        return t[idx][curOr] = take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxOr = 0;

        for(int& num: nums) {
            maxOr = maxOr | num;
        }

        vector<vector<int>> t(n+1, vector<int>(maxOr+1, -1));

        int curOr = 0;
        return solve(0, curOr, nums, maxOr, t);
    }
};