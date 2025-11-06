class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> s1_count(26, 0), s2_count(26, 0);

        // Count frequencies of s1 and the first window of s2
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        // Slide over s2 and check the count every iteration
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (s1_count == s2_count) return true;

            // Update the count
            s2_count[s2[i] - 'a']--;
            s2_count[s2[i + s1.length()] - 'a']++;
        }

        // Check the last iteration
        return s1_count == s2_count;
    }
};