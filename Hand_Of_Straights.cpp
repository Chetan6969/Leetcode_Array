class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false; // If the number of cards is not divisible by groupSize,cannot rearrange them
        }

        std::map<int, int> count; // Map to store the count of each card value.
        for (int card : hand) {
            count[card]++;
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            int value = it->first;
            int freq = it->second;
            if (freq > 0) {
                for (int i = 1; i < groupSize; ++i) {
                    if (count[value + i] < freq) {
                        return false; // If there are not enough consecutive cards to form a group.
                    }
                    count[value + i] -= freq; // Reduce the count of consecutive cards.
                }
            }
        }

        return true; // If all groups can be formed, return true.
    }
};
        
    