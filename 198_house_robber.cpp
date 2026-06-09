class Solution {
public:
    /*
    The fault here was thinking that I had to go backwards and then re use the dp
    it's actually going forward, it completes the recursion, stores everything and then
    reuses it in the next path
    */
    int rob(vector<int>& nums) {
        int robNextPlusOne = 0; //max money from ind+2
        int robNext = 0;        //max money from ind+1
        for(int i = nums.size()-1; i >= 0; i--) {
            int curr = max(nums[i] + robNextPlusOne, robNext);
            robNextPlusOne = robNext;
            robNext = curr;
        }
        return robNext;
    }
};