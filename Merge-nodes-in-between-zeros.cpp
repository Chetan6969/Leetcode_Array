
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // Initialize a dummy node to simplify handling the new list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        ListNode* iterator = head->next; // Skip the first 0 node
        int sum = 0;

        while (iterator != nullptr) {
            if (iterator->val == 0) {
                // Create a new node with the sum and add it to the result list
                current->next = new ListNode(sum);
                current = current->next;
                sum = 0; // Reset sum for the next segment
            } else {
                sum += iterator->val; // Accumulate the sum of values
            }
            iterator = iterator->next;
        }

        return dummy->next; // Skip the dummy node and return the result 
    }
};