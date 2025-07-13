class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());

        int i = 0, j = 0;
        int count = 0;
        // int mini = min(n, m);

        while(i < n && j < m) {
            if(players[i] > trainers[j]) {
                i++;
            }
            else {
                count++;
                i++;
                j++;
            }
        }
        return count;


    }
};