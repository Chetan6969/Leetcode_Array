using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {

        if (height.empty()) {
            return 0;  // Early return for empty input
        }
        
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            max_area = max(max_area, width * h);
            
            // Move the pointers
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};