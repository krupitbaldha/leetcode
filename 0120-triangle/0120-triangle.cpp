class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<int>front(n,0),curri(n,0);

        for (int j = 0; j < n; j++) {
            front[j] = tri[n-1][j];
        }

        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = tri[i][j] + front[j];
                int diag = tri[i][j] + front[j+1];
               curri[j] = min(down, diag);
            }
            front = curri;
        }

        return front[0];
    }
};
