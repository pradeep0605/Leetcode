class Solution {
public:
    int LCIS_Length(vector<int>& arr) {
        int n = arr.size();
        // Boundary case.
        if (n == 0) { return 0; }
        int max_length = 1, curr_count = 1;
        for (int i = 1; i < n; ++i) {
            // Is current element in 'increasing' order than previous ?
            if (arr[i - 1] < arr[i]) {
                curr_count++;   
            } else { curr_count = 1; /* start counting new LCIS */ }
            // Update max_length if we found a better solution.
            max_length = max(curr_count, max_length);
        }
        return max_length;
    }
    
    int findLengthOfLCIS(vector<int>& nums) {
        return LCIS_Length(nums);
    }
};