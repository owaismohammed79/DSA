class Solution {
private:
    void fn(vector<int>& nums, int n, int i) {
        while(true) {
            int smallest = i;
            int left = 2*i+1; //Basic rule in binary tree
            int right = 2*i+2;

            //smallest dhundo tumhare teeno me se aur usko swap kardo
            if(left < n && nums[left] < nums[smallest]) {
                smallest = left;
            }
            if(right < n && nums[right] < nums[smallest]) {
                smallest = right;
            }

            if(smallest != i) {
                swap(nums[i], nums[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

public:
    void buildMinHeap(vector<int>& nums) {
        int n = nums.size();
        //ham n/2-1 se start karte he cox n/2 aur uske baad n-1 tak ke nodes agar array me represent karte he to wo leaf nodes hote he
        for(int i = n/2-1; i >= 0; i--) {
            fn(nums, n, i);
        }
    }
};