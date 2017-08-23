class Solution {
public:
    int romanToInt(string s) {
        int s_size = s.size();
        int roam_to_int_map[256] = {0};
        roam_to_int_map['I'] = 1;
        roam_to_int_map['V'] = 5;
        roam_to_int_map['X'] = 10;
        roam_to_int_map['L'] = 50;
        roam_to_int_map['C'] = 100;
        roam_to_int_map['D'] = 500;
        roam_to_int_map['M'] = 1000;
        int num = 0;
        int last_num = 0;
        for (int i = s_size - 1; i >= 0; --i) {
            if (last_num <= roam_to_int_map[s[i]]) {
                num += roam_to_int_map[s[i]];
            } else {
                num -= roam_to_int_map[s[i]];
            }
            last_num = roam_to_int_map[s[i]];
        }
        return num;
    }
};