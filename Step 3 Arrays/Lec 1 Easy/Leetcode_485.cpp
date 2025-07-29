class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), maxConsecutive = 0, currConsecutive = 0;

        for (int i = 0; i < n; i++){
            if (nums[i] == 1) currConsecutive ++;
            else currConsecutive = 0;

            if (currConsecutive > maxConsecutive) maxConsecutive = currConsecutive;

        }
        return maxConsecutive;
    }
};
