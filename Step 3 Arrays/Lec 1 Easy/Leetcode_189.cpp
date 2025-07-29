// reversing solution 
// O(N) time
// O(1) spacejj
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        // reverse entire array 
        reverse(nums, 0, n-1); 
        // reverse first k elements 
        reverse(nums, 0, k-1);
        // reverse remaining array 
        reverse(nums, k, n-1);
    }

private: 
    void reverse(vector<int>& nums, int i, int j){
        while (i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++; 
            j--;
        } 
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp;
        k = k % n;
        // last k elements come front 
        for (int i = n-k; i < n; i++){
            temp.push_back(nums[i]);
        }
        // then the rest of the array 
        for (int i = 0; i < n-k; i++){
            temp.push_back(nums[i]);
        }
        // replace nums

        for (int i = 0; i < n; i++){
            nums[i] = temp[i];
        }
    }
};
