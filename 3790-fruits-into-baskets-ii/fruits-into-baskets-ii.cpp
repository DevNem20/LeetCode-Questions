class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = fruits.size();
        vector<bool> vis(n, false);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(baskets[j] >= fruits[i] && vis[j] == false) {
                    count++;
                    vis[j] = true;
                    break;
                }
            }
        }
        return n - count;
    }
};