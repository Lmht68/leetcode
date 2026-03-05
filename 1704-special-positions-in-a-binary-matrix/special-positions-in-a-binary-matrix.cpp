class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            int row_ones = 0;
            int col_id = -1;
            
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    row_ones++;
                    col_id = j;
                }
            }
            
            if (row_ones == 1) {
                int col_ones = 0;

                for (int k = 0; k < m; k++) {
                    if (mat[k][col_id] == 1) {
                        col_ones++;
                    }
                }

                if (col_ones == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};