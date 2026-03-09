class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;

        for (int x : rods) {
            unordered_map<int, int> current(dp);

            for (auto it: current) {
                int d = it.first;
                dp[d + x] = max(dp[d + x],current[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], current[d] + min(d, x));
            }
        }
        
        return dp[0];
    }
};