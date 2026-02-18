class Solution {
public:
    bool hasAlternatingBits(int n) {
        /** Example n = 5
            n = 101
            n >> 1 = 010
            XOR: 101 ^ 010 = 111
            x + 1 = 111 + 1 = 1000
            111 & 1000 = 0000
        */
        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};