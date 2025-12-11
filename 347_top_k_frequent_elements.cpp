/*
So What if I store the freq and sort accordingly in a pair?? all good
Pehli cheez to yeh he ki map ki tarah freq track karni h nd then I'd have to arrange according
to the freq, but I can only access freq using the number? So custom fn to 
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int el:nums) freq[el]++;
        
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        for(auto p : freq) {
            buckets[p.second].push_back(p.first);
        }
        
        vector<int> ans;
        for(int i = n; i >= 0 && ans.size()< k; i--) {
            for(int el : buckets[i]) {
                ans.push_back(el);
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};