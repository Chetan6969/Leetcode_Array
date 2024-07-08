#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n = nums.size();
        
        // If the array has 4 or fewer elements, we can make all elements equal in at most 3 moves.
        if (n <= 4) return 0;
        
        // Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Initialize minimum difference as the maximum possible difference
        int min_diff = INT_MAX;
        
        // Evaluate the possible scenarios by changing up to three elements
        // 1. Change three largest elements to the smallest element
        min_diff = std::min(min_diff, nums[n-4] - nums[0]);
        // 2. Change two largest elements and one smallest element to the second smallest element
        min_diff = std::min(min_diff, nums[n-3] - nums[1]);
        // 3. Change one largest element and two smallest elements to the third smallest element
        min_diff = std::min(min_diff, nums[n-2] - nums[2]);
        // 4. Change three smallest elements to the largest element
        min_diff = std::min(min_diff, nums[n-1] - nums[3]);
        
        return min_diff;
    }
};