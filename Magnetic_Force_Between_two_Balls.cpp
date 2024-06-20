#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& position, int m) {
        // Sort the basket positions
        std::sort(position.begin(), position.end());
        
        // Initialize binary search bounds
        int low = 1;
        int high = position.back() - position.front();
        
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if it is possible to place m balls with at least `mid` distance
            if (canPlaceBalls(position, m, mid)) {
                result = mid;  // Update result as mid is a feasible solution
                low = mid + 1; // Try for a larger minimum distance
            } else {
                high = mid - 1; // Try for a smaller minimum distance
            }
        }
        
        return result;
    }

private:
    bool canPlaceBalls(const std::vector<int>& position, int m, int minDist) {
        int count = 1;  // Place the first ball
        int lastPos = position[0];
        
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minDist) {
                // Place next ball
                count++;
                lastPos = position[i];
                
                if (count == m) {
                    return true;
                }
            }
        }
        
        return false;
    }
};