class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        //Just use like a vector26 size vector??
        vector<int> mpp(26, 0);
        int start = 0, end = 0, max_el = 0;
        while(end < s.size()){
            mpp[s[end]-'a']++;
            while(mpp[s[end]-'a'] > 1){
                mpp[s[start]-'a']--;
                start++;
            }
            max_el = max(max_el, end-start+1);
            end++;
        }
        return max_el;
    }
};
