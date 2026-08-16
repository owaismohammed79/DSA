class Solution {
public:
    void generateSums(const vector<int>& arr, int index, int count, int current_sum, vector<vector<int>>& sums) {
        if(index == arr.size()) {
            sums[count].push_back(current_sum);
            return;
        }
        generateSums(arr, index+1, count, current_sum, sums);
        generateSums(arr, index+1, count+1, current_sum+arr[index], sums);
    }

    int minimumDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size()/2;

        vector<int> left(nums.begin(), nums.begin()+n);
        vector<int> right(nums.begin()+n, nums.end());

        vector<vector<int>> left_sums(n + 1);
        vector<vector<int>> right_sums(n + 1);

        generateSums(left, 0, 0, 0, left_sums);
        generateSums(right, 0, 0, 0, right_sums);

        for(int k = 0; k <= n; k++) sort(right_sums[k].begin(), right_sums[k].end());

        int min_diff = INT_MAX;
        int target = total/2;

        for(int k = 0; k <= n; k++) {
            int right_k = n-k;
            for(int a : left_sums[k]) {
                auto it = lower_bound(right_sums[right_k].begin(), right_sums[right_k].end(), target - a);

                if(it != right_sums[right_k].end()) {
                    int half1 = a + *it;
                    min_diff = min(min_diff, abs(half1 - (total - half1)));
                }

                if(it != right_sums[right_k].begin()) {
                    int half1 = a + *prev(it);
                    min_diff = min(min_diff, abs(half1 - (total - half1)));
                }
            }
        }

        return min_diff;
    }
};