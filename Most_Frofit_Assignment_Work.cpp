#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    vector<pair<int, int>> jobs;
    for (int i = 0; i < difficulty.size(); ++i) {
        jobs.push_back({difficulty[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());

    int max_profit = 0;
    int total_profit = 0;
    int i = 0;
    
    for (int ability : worker) {
        while (i < jobs.size() && ability >= jobs[i].first) {
            max_profit = max(max_profit, jobs[i].second);
            i++;
        }
        total_profit += max_profit;
    }
    
    return total_profit;
}
};