#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_count;
        remainder_count[0] = 1;  // Initial remainder count for subarrays starting from index 0
        int prefix_sum = 0;
        int result = 0;
        
        for (int num : nums) {
            prefix_sum += num;
            int remainder = ((prefix_sum % k) + k) % k;  // Ensure non-negative remainder
            
            // Add the count of subarrays which have the same remainder
            if (remainder_count.find(remainder) != remainder_count.end()) {
                result += remainder_count[remainder];
            }
            
            // Increment the count of this remainder
            remainder_count[remainder]++;
        }
        
        return result;
    }
};
