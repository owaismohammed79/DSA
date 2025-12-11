/*
So What if I store the freq and sort accordingly in a pair?? all good
Pehli cheez to yeh he ki map ki tarah freq track karni h nd then I'd have to arrange according
to the freq, but I can only access freq using the number? So custom fn to 
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto custom_greater = [](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(custom_greater)> minH(custom_greater);
        unordered_map<int, int> mpp;
        for(int el: nums){
            mpp[el]++;
        }
        for(pair<int, int> p: mpp) {
            minH.push({p.first, p.second});
            if(minH.size() > k) minH.pop();
        }
        vector<int> ans;
        while(minH.size()){
            ans.push_back(minH.top().first);
            minH.pop();
        }
        return ans;
    }
};