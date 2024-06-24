#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flip(n + 1); // flip[i] tracks the number of flips ending at position i
        int flipCount = 0; // total number of flips performed
        
        int currFlip = 0; // tracks current flip state
        for (int i = 0; i < n; ++i) {
            currFlip += flip[i];
            // Apply the current flip state to nums[i]
            if ((nums[i] + currFlip) % 2 == 0) { // nums[i] needs to be flipped
                if (i + k > n) return -1; // if we cannot flip a segment of length k starting from i
                ++flipCount; // flip nums[i]
                ++currFlip; // toggle flip state
                ++flip[i + k]; // mark the end of the flip at i+k
            }
        }
        
        return flipCount;
    }
};