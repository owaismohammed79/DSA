class Solution {
public:
    int search(vector<int>& nums, int target) {
        //The moment the next ele is smaller than the current one
        //We've found the index that this array is rotated around, then we could
        //perform Binary search which is like logn
        //But what if I can simply do
        int n = nums.size(), k = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] < nums[i]) {
                k = i+1;
                break;
            }
        }
        int i = 0, j = n-1;
        if(target >= nums[k] && target <= nums[n-1]) {
            i = k;
            j = n - 1;
        } else {
            i = 0;
            j = k - 1;
        }
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                i = mid+1;
            } else j = mid-1;
        }
        return -1;
    }
};