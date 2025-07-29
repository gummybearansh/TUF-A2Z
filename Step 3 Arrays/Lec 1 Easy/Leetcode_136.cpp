class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), XOR = 0;
        for (int i = 0; i < n; i++){
            XOR ^= nums[i];
        }
        return XOR;
    }
};
