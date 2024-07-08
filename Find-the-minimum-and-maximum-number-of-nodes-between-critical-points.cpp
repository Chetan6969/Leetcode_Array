class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }

        vector<int> criticalPoints;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = next;
            index++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        for (int i = 1; i < criticalPoints.size(); i++) {
            int distance = criticalPoints[i] - criticalPoints[i - 1];
            minDistance = min(minDistance, distance);
        }

        return {minDistance, maxDistance};
    }
};