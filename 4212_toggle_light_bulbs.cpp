class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < bulbs.size(); i++){
            mpp[bulbs[i]]++;
        }
        vector<int> ans;
        for(auto p: mpp){
            if(p.second%2) ans.push_back(p.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};