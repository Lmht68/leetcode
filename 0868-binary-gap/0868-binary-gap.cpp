class Solution {
public:
    int binaryGap(int n) {
        int start = -1, end = -1;
        int result = 0;

        for (int i = 0; i < 32; i++) {
            int d = (n >> i) & 1;

            if (d) {
                start = (start == -1) ? i : start;
                end = (end == -1) ? start : i;
                result = max(result, end - start);
                start = end;
            }
        }

        return result;
    }
};