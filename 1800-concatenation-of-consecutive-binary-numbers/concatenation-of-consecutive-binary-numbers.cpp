class Solution {
public:
    int concatenatedBinary(int n) {
        constexpr int kMod = 1000000007;
        long ans = 0;

        for (int i = 1; i <= n; ++i) {
            ans = ((ans << (int)(log2(i) + 1)) % kMod + i) % kMod;
        }

        return ans;
    }
};