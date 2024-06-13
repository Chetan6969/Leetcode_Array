#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        
        int totalMoves = 0;
        
        for (size_t i = 0; i < seats.size(); ++i) {
            totalMoves += std::abs(seats[i] - students[i]);
        }
        
        return totalMoves;
    }
};