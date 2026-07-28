class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int end = 0, n = arr.size(), curr = 0, max_el = INT_MIN;
        while(end < n){
            curr += arr[end++];
            max_el = max(max_el, curr);
            if(curr < 0) curr =0;
        }
        return max_el;
    }
};