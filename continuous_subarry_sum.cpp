#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Create a hash map to store the remainder and the index
        unordered_map<int, int> remainderIndexMap;
        // Initialize the map with remainder 0 at index -1
        remainderIndexMap[0] = -1;
        int cumulativeSum = 0;

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            cumulativeSum += nums[i];
            int remainder = (k == 0) ? cumulativeSum : cumulativeSum % k;

            // Adjust negative remainder to be within the range [0, k-1]
            if (remainder < 0) remainder += k;

            // Check if this remainder has been seen before
            if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
                // Ensure the subarray length is at least 2
                if (i - remainderIndexMap[remainder] > 1) {
                    return true;
                }
            } else {
                // Store the index of the first occurrence of this remainder
                remainderIndexMap[remainder] = i;
            }
        }

        // If no valid subarray is found, return false
        return false;
    }
};