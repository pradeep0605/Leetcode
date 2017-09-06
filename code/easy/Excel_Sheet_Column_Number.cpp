class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size();
        int i = size - 1;
        int power = 1;
        int result = 0;
        while (i >= 0) {
            result = result + (s[i] - 'A' + 1) * power;
            i--;
            power *= 26;
        }
        return result;
    }
};