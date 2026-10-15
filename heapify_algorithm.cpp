class Solution {
private:
    void heapifyUp(vector<int> &nums, int i) {
        while(i > 0) {
            int parent = (i - 1) / 2;
            if(nums[i] < nums[parent]) {
                swap(nums[i], nums[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(vector<int> &nums, int i) {
        int n = nums.size();
        while(true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < n && nums[left] < nums[smallest]) smallest = left;
            if(right < n && nums[right] < nums[smallest]) smallest = right;
            if(smallest != i) {
                swap(nums[i], nums[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

public:
    void heapify(vector<int> &nums, int ind, int val) {
        if(ind < 0 || ind >= nums.size()) return;

        int oldVal = nums[ind];
        nums[ind] = val;

        if(val < oldVal) {
            heapifyUp(nums, ind);
        } else if(val > oldVal) {
            heapifyDown(nums, ind);
        }
    }
};