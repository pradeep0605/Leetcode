class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        int map[256] = {0};
        int max_len = 0;
        while (j < n && i <= j) {
            while(++map[s[j]] <= 1 && j < n) {
                j++;
            }
            
            // Update max_len if the current non-repeating substring is greater
            // than till-known max length
            if ((j - i) > max_len) {
                max_len = j - i;
            }
            
            while(i <= j && map[s[j]] >= 2) {
                map[s[i]]--;
                i++;
            }
            j++;
        }
        return max_len;
    }
};