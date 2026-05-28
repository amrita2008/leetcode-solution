class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c) {
        unordered_set<int> st;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || st.count(num))
                    return false;
                st.insert(num);
            }
        }

        int rsum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        for (int i = 0; i < 3; i++) {
            int sumR = grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2];
            if (sumR != rsum)
                return false;

            int sumC = grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i];
            if (sumC != rsum)
                return false;
        }

        int diaSum = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int antiDiaSum = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
        if (diaSum != rsum || antiDiaSum != rsum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (isValid(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};