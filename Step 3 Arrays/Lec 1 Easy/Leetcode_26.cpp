class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1, n = nums.size();
        // i -> finds unique
        // j -> puts it in the start
        for (int i = 1; i < n; i++){
            // found unique
            if (nums[i] != nums[i-1]) nums[j++] = nums[i];
        }
        // because j tracks all unique elements 
        return j;
    }
};
