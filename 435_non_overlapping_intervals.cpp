class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //The catch is that this is the inverse of the n meetings in 1 room problem
        //That prb we find maximum no of meetings that can be done in 1 romm i.e max no
        //of intervals which can be together. So if we simply subtract this from the total
        //we'll get minimum no of intervals to be removed
        //Sorting according to the ending time
        sort(intervals.begin(), intervals.end(), [](auto& a,auto& b) {
            return a[1] < b[1];
        });
        int ans = 1, lastEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= lastEnd){
                ans++;
                lastEnd = intervals[i][1];
            }
        }
        return (int)intervals.size()-ans;
    }
};