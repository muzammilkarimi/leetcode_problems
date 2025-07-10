class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<pair<int, int>> meetings(n);
        
        for (int i = 0; i < n; ++i) {
            meetings[i] = {startTime[i], endTime[i]};
        }

        sort(meetings.begin(), meetings.end()); 

        vector<int> gaps;
        gaps.push_back(meetings[0].first); 

        for (int i = 1; i < n; ++i) {
            gaps.push_back(meetings[i].first - meetings[i - 1].second); 
        }

        gaps.push_back(eventTime - meetings.back().second);  

        int sz = gaps.size();
        vector<int> largestRight(sz, 0), largestLeft(sz, 0);

        for (int i = sz - 2; i >= 0; --i) {
            largestRight[i] = max(largestRight[i + 1], gaps[i + 1]);
        }

        for (int i = 2; i < sz; ++i) {
            largestLeft[i] = max(largestLeft[i - 1], gaps[i - 2]);
        }

        int maxFreeDuration = 0;

        for (int i = 1; i < sz; ++i) {
            int meetingTime = meetings[i - 1].second - meetings[i - 1].first;

        
            if (meetingTime <= max(largestLeft[i], largestRight[i])) {
                maxFreeDuration = max(maxFreeDuration, gaps[i - 1] + gaps[i] + meetingTime);
            }

        
            maxFreeDuration = max(maxFreeDuration, gaps[i - 1] + gaps[i]);
        }

        return maxFreeDuration;
    }
};