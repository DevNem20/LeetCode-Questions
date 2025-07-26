class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid = 0;

        vector<vector<int>> conflictP(n+1);
        for(auto& p: conflictingPairs) {
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);

            conflictP[b].push_back(a);
        }

        int maxConflict  = 0;
        int smaxConflict = 0;

        vector<long long> extra(n+1, 0);

        for(int end = 1; end <= n; end++) {
            for(int& u: conflictP[end]) {
                if(u >= maxConflict) {
                    smaxConflict = maxConflict;
                    maxConflict  = u;
                }
                else if(u > smaxConflict) {
                    smaxConflict = u;
                }
            }

            valid += end - maxConflict;
            extra[maxConflict] += maxConflict - smaxConflict;

        }
        return valid + *max_element(extra.begin(), extra.end());
    }
};