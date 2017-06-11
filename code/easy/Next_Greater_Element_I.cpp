class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result = vector<int>();
        unordered_map<int, int> num_next_map =  unordered_map<int, int>();
        std::stack <int> stk = std::stack <int>();
    
        for(auto itr: nums) {
            if(stk.empty() || stk.top() >= itr) {
                stk.push(itr);
            } else {
                while(!stk.empty() && stk.top() < itr) {
                    num_next_map[stk.top()] = itr;
                    stk.pop();
                }
                stk.push(itr);
            }
        }
        
        while(!stk.empty()) {
            num_next_map[stk.top()] = -1;
            stk.pop();
        }
        
        for(auto itr: findNums) {
            result.emplace_back(num_next_map[itr]);
        }
        
        return result;
    }
};