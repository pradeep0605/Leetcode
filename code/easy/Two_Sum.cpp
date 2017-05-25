class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map = unordered_map<int, int>();
        vector<int> result = vector<int>();
        
        int i = 0;
        int n = nums.size();
        for(i = 0; i < n; ++i) {
            if (map[target - nums[i]] != 0 ) {
                result.push_back(map[target - nums[i]] - 1);
                result.push_back(i);
                return result;
            } else {
                map[nums[i]] = i + 1;
            }
        }
        return result;
    }
};