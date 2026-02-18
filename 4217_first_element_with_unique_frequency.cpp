class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mpp /*ele and freq*/, mpp2; //freq and count of freq
        for(int el: nums) mpp[el]++;
        for(auto p: mpp) mpp2[p.second]++;
        for(int el: nums) {
            //The first element who's count is 0
            //count of el is mpp[el]
            if(mpp2[mpp[el]] == 1) return el;
        }
        return -1;
    }
};