
class Solution {
public:
    int n, m;
    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, -1, 1};
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m); }
    void dFS(int r, int c, vector<vector<char>>& grid) {
        for (int k = 0; k < 4; k++) {
            int newR = r + rows[k];
            int newC = c + cols[k];
            if (isValid(newR, newC) && grid[newR][newC] == '1') {
                grid[newR][newC] = '0';
                dFS(newR, newC, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int noOfIslands = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    noOfIslands++;
                    grid[i][j] = '0';
                    dFS(i, j, grid);
                }
            }
        }

        return noOfIslands;
    }
};