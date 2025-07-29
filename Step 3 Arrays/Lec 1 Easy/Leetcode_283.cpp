class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // brute force TC -> O(N) SC -> O(N)
        // store all unique elements in a new array
        // see difference in unique elements and nums
        // add 0s to nums

        vector<int> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] != 0) temp.push_back(nums[i]);
        }
        int uniqueSize = temp.size();
        for (int i = 0; i < n-uniqueSize; i++){
            temp.push_back(0);
        }

        // replace it with nums 
        for (int i = 0; i < n; i++){
            nums[i] = temp[i];
        }
    }
};
