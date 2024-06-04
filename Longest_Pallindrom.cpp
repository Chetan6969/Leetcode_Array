class Solution {
public:
    int longestPalindrome(string s)
    {
          // Frequency array for ASCII characters
        int charCount[128] = {0};
        
        // Count the frequency of each character
        for (char c : s) {
            charCount[c]++;
        }
        
        int palindromeLength = 0;
        bool hasOddCount = false;
        
        // Calculate the length of the longest palindrome
        for (int count : charCount)
        {
            if (count % 2 == 0) {
                palindromeLength += count;  // Add even counts completely
            } else {
                palindromeLength += count - 1;  // Add the largest even part
                hasOddCount = true;
            }
        }
        
        // If there's any character with an odd count, we can add one to the length
        if (hasOddCount) {
            palindromeLength++;
        }
      return palindromeLength;
    }
      
};