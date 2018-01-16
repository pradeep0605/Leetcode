// A map from character to its last occurance position in the string.
typedef unordered_map<char, int> LastOccurMap;
class Solution {
    
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        LastOccurMap last_occur_map;
        /* Make a note of last occurance of each characetr */
        for (int i = 0; i < S.size(); ++i) {
            last_occur_map[S[i]] = i;
        }
        
        int curr_index = 0, farthest_index = 0, window_start_index = 0;
        while (curr_index < S.size()) {
            farthest_index = max(farthest_index,  last_occur_map[S[curr_index]]);
            // Check for end of a window.
            if (curr_index == farthest_index) {
                result.push_back(farthest_index - window_start_index + 1);
                // Setup a new window.
                window_start_index = curr_index + 1;
            }
            curr_index++;
        }
        
        return result;
    }
};