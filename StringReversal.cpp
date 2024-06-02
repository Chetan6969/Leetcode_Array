class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Swap characters
            swap(s[left], s[right]);
            // Move towards the center
            left++;
            right--;
        }
          
    }
};