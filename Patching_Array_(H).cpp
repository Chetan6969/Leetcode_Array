#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        int patches = 0;
        long long miss = 1; // 'miss' stores the smallest number that we cannot form
        int i = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};