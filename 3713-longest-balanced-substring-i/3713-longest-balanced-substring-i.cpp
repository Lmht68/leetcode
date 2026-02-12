class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
            a[i] = s[i] - 'a';

        int result = 0;
        for (int left = 0; left < n; ++left) {
            if (n - left <= result)
                break;
            
            int count[26] = {0};
            int uniq = 0, maxFreq = 0;

            for (int right = left; right < n; ++right) {
                int i = a[right];

                if (count[i] == 0)
                    ++uniq;
                
                ++count[i];

                if (count[i] > maxFreq)
                    maxFreq = count[i];
                
                int curr = right - left + 1;

                if (uniq * maxFreq == curr && curr > result)
                    result = curr;
            }
        }

        return result;
    }
};