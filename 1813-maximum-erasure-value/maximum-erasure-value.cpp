class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        unordered_set<int> st;
        int i = 0, j = 0;
        int sum = 0;
        while(j < n) {
            if(!st.count(nums[j])) {
                sum += nums[j];
                maxi = max(maxi, sum);
                st.insert(nums[j]);
                j++;
            }
            else{
              while(i < n && st.count(nums[j])) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
              }
            }
        }
        return maxi;
    }
};