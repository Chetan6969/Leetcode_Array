class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap nums[low] and nums[mid]
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Move mid pointer to the right
                mid++;
            } else {
                // Swap nums[mid] and nums[high]
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};