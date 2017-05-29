short sort_mem[20004] = {0};

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        short *map = &sort_mem[10000];
        int n = nums.size();
        int sum = 0;
        int index = 10000;

        for(int i = 0; i < n; ++i) {
            map[nums[i]]++;
        }
        

        for(int j = 0; j < n / 2; ++j) {
            int a = 0, b = 0;
            while(map[index] == 0) index--;
            map[index]--; a = index;
            while(map[index] == 0) index--;
            map[index]--; b = index;
            sum += index;
        }
        return sum;
    }
    
};

