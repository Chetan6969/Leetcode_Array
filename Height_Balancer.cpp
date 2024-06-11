#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        // Find the maximum height to determine the size of the count array
        int max_height = *std::max_element(heights.begin(), heights.end());
        
        // Create a count array to store the frequency of each height
        std::vector<int> count(max_height + 1, 0);
        
        // Populate the count array with the frequencies of each height
        for (int height : heights) {
            count[height]++;
        }
        
        // Initialize the mismatch counter and the current height pointer
        int mismatchCount = 0;
        int current_height = 0;
        
        // Compare the heights array with the expected order constructed on the fly
        for (int height : heights) {
            // Find the next non-zero count in the count array
            while (count[current_height] == 0) {
                current_height++;
            }
            
            // Compare the current height with the next expected height
            if (height != current_height) {
                mismatchCount++;
            }
            
            // Decrement the count for the current height
            count[current_height]--;
        }
        
        return mismatchCount;
    }
};