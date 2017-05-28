int count_map[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

class Solution {
    
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int count = 0;
        
        for(int i = 0; i < 8; ++i) {
            count += count_map[res % 16];
            res >>= 4;
        }
        return count;
    }
};

