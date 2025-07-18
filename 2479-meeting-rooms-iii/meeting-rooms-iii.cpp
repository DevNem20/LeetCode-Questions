class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings), end(meetings));
        vector<long long> lastAvailableAt(n, 0);
        vector<int> roomUsedCount(n, 0);

        for(vector<int>& meet: meetings) {
            int start = meet[0];
            int end   = meet[1];
            int duration = end - start;
            bool found = false;


            long long earlyEndRoomTime = LLONG_MAX;
            int earlyEndRoom = -1;

            for(int room = 0; room < n; room++) {
                if(lastAvailableAt[room] <= start) {
                    lastAvailableAt[room] = end;
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }

                if(lastAvailableAt[room] < earlyEndRoomTime) {
                    earlyEndRoomTime  = lastAvailableAt[room];
                    earlyEndRoom = room;
                }


            }

            if(!found) {
                lastAvailableAt[earlyEndRoom] += duration;
                roomUsedCount[earlyEndRoom]++;
            }
            
        }

        
            int resultRoom = -1;
            int maxUse = 0;

            for(int room = 0; room < n; room++) {
                if(roomUsedCount[room] > maxUse) {
                    maxUse = roomUsedCount[room];
                    resultRoom = room;
                }
            }

        return resultRoom;
    }
};