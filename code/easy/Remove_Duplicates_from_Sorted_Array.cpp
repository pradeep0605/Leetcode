class Solution {
public:
    
    
    int removeDuplicates(vector<int>& arr) {
        int i = 0, j = 0, n = arr.size();
        while (j < n) {
            arr[i] = arr[j];
            while (arr[i] == arr[j]) { j++; }
            i++;
        }
        return i;
    }
    
    
};