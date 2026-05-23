class Solution {
public:
    //At each step I just need to find whether I can reach the last index or not,
    //And save that from this index the final index can be reached or not...
    //So if I can reach the last index from the 2nd last one, then I come back in the 
    //recursion tree and then check from farther away
    //The thing is, I realized the last jump length also matters
    bool fn(vector<int>& s, int lastStep, int curr, unordered_map<string, bool>& dp) {
        if(curr == s.size() - 1) return true;

        string str = to_string(curr) + "_" + to_string(lastStep);
        if(dp.count(str)) return dp[str];

        // we have 3 routes k-1, k, k+1 steps
        for (int i = lastStep - 1; i <= lastStep + 1; i++) {
            if(i > 0) {
                int targetPos = s[curr] + i;
                auto it = lower_bound(s.begin() + curr + 1, s.end(), targetPos);
                if(it != s.end() && *it == targetPos) {
                    int nextIdx = distance(s.begin(), it);                
                    if(fn(s, i, nextIdx, dp)) return dp[str] = true;
                }
            }
        }
        return dp[str] = false;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<string, bool> dp;
        if(stones.size() > 1 && stones[1] != 1) return false;
        return fn(stones, 1, 1, dp);
    }
};