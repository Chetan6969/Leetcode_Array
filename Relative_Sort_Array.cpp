class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        unordered_map<int, int> count;
        
        // Count the occurrences of each element in arr1
        for (int num : arr1) {
            count[num]++;
        }
        
        // Add elements from arr2 in the specified order
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        
        // Add remaining elements that were not in arr2
        vector<int> rest;
        for (int num : arr1) {
            if (count[num] > 0) {
                rest.push_back(num);
                count[num]--;
            }
        }
        
        // Sort the remaining elements
        sort(rest.begin(), rest.end());
        
        // Add sorted remaining elements to result
        result.insert(result.end(), rest.begin(), rest.end());
        
        return result;
    }
};
