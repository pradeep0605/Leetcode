class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        if (n == 0)
            return nums;
        int m = nums[0].size();
        
        if (((n*m) != (r*c)) || (n == r && m == c)) {
            return nums;
        }
        
        vector<vector<int>> result = vector<vector<int>>();
        int p = -1, q = c - 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                // insert_element(result,nums[i][j])
                if (q == (c - 1)) {
                    vector<int> temp = vector<int>(c);
                    result.push_back(temp);
                    p++;
                    q = 0;
                    
                } else {
                    q++;
                }
                result[p][q] = nums[i][j];
            }
        }
        return result;
    }
};
