class Solution {
public:
   

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
  vector<int>prev(m,0);
  for(int i =0;i<n;i++){
    vector<int>curri(m,0);
    for(int j=0;j<m;j++){
        if(i==0&&j==0)curri[i] = grid[i][j];
        else{
            int up = grid[i][j];
            if(i>0) up+=prev[j];
            else up+=1e9;
            int left = grid[i][j];
            if(j>0) left += curri[j-1];
         else left +=1e9;

         curri[j] = min(up,left);
        }
    }
    prev = curri;
  }
        return prev[m-1];
    }
};