#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        // Pair of (capital requirement, profit)
        std::vector<std::pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        
        // Sort projects based on their capital requirement
        std::sort(projects.begin(), projects.end());
        
        // Max-heap to store the profits of the projects we can start
        std::priority_queue<int> maxHeap;
        
        int index = 0;
        int n = projects.size();
        
        // Try to complete at most k projects
        for (int i = 0; i < k; ++i) {
            // Push all projects that can be started with the current capital into the max-heap
            while (index < n && projects[index].first <= w) {
                maxHeap.push(projects[index].second);
                ++index;
            }
            
            // If there are no available projects to start, break early
            if (maxHeap.empty()) {
                break;
            }
            
            // Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};