class Solution {
public:
    int round_two_powers(int num) {
        int divisor = 16;
        int bit_count = 0;
        
        /* Doing binary search here */
        while (divisor >= 1) {
            /* Check if the first part of number is greater than zero.
             * If yes, this means the highest set bit is in the first half */
            if (num >> divisor) {
                /* as highest set bit is in the second half, we would need divisor number of 
                * bit shifts to get to first half */
                bit_count += divisor;
                /* We need to recurse in the first half again, thus reduce the num to only 
                 * first half */
                num >>= divisor;
                
            } else {
                /* second half. As first half is zero, the highest bit should be in
                 * the second half*/
                
            }
            /* We keep halving the division of bits. I.e., we divide the number into 16 bit two chunks.
             * Then we divide it into two 8-bit chunks the, two 4-bits chunks till two 1-bits cunks
             */
            divisor /= 2;
        }
        /* bit_count will tell the exact highest bit set. We need one bit more to that */
        return 1 << (bit_count + 1);
    }
    int findComplement(int num) {
        int two_powers = round_two_powers(num);
        cout <<"Round off = " << two_powers << endl;
        return num ^ (two_powers - 1);
    }
};