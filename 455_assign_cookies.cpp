/*
Sooo maximize content children, what can be a greedy approach?Sorting is a good app
both vectors ko sort kia and now check from smallest to  biggest in both arrays, if child is content
with current cookie move both pointers if child isn't then simply move the pointer in the cookie arr
forward as this cookie can never be assigned to someone further, keep doing this until either pointers
reach the end??
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0, ptr1 = 0, ptr2 = 0, s1 = g.size(), s2 = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(ptr1 < s1 && ptr2 < s2) {
            if(s[ptr2] >= g[ptr1]) {
                ptr1++;
                ptr2++;
                ans++;
            } else {
                ptr2++;
            }
        }
        return ans;
    }
};