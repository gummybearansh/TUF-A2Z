class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while (low <= high){
            int mid = (low + high) / 2;
            // lies on right side
            if (target > nums[mid]) low = mid + 1;
            // lies on left side
            else if (target < nums[mid]) high = mid - 1;
            else return mid;
        }
        return -1;
    }
};
