class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;

        // Flatten into 1D
        vector<int> flat;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flat.push_back(grid[i][j]);
            }
        }

        // Shift using modulo
        k = k % total;
        vector<int> shifted(total);
        for (int i = 0; i < total; i++) {
            shifted[(i + k) % total] = flat[i];
        }

        // Build back into 2D
        vector<vector<int>> result(n, vector<int>(m));
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = shifted[idx++];
            }
        }

        return result;
    }
};
