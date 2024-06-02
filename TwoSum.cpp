class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> _map;
        for(int i=0;i<nums.size();++i)
        {
            int number = nums[i];
            int compliment = target -number;
            auto iterative =_map.find(compliment);
            if(iterative!= _map.end())
            {
                return {iterative->second,i};
            }
            _map[number] = i;
        }
        return {};       
    }
};