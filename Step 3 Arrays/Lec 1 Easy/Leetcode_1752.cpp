// check if array is sorted and rotated 

// optimal solution 
// if array is breaking ascending order -> count ++;
// if array's last element is larger than first (not rotated) -> count++
// if count is 0 -> all elements are equal, if count is 1 -> either breaks order once or is rotated and is ascending
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0; 
        int n = nums.size();
        for (int i = 1; i < n; i++){
            // when ascending breaks
            if (nums[i-1] > nums[i]) count++;
        }

        // means array is not rotated (so there shud be no breaks)
        if (nums[n-1] > nums[0]) count++;

        if (count <= 1) return true;
        return false;
    }
};

// my solution -> loop over array twice (incase it is rotated)
// if there are more than 2 decreases -> array is not sorted 
class Solution {
public:
    bool check(vector<int>& nums) {
        int decreases = 0;
        int n = nums.size();
        // loop over array twice can allow 2 decreases
        for (int i = 1; i < 2*n; i++){
            if (nums[i%n] < nums[(i-1)%n]){
                decreases ++;
            }
        }
        if (decreases > 2) return false;
        return true;
    }
};
