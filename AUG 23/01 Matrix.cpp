class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int> (n)), ans(m, vector<int> (n));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (mat[i][j] == 0) q.push(vector<int>({i, j, 0})), visited[i][j] = 1;
            }
        }
        
        while(q.size()) {
            vector<int> par = q.front();
            q.pop();
            int r = par[0], c = par[1], d = par[2];
            ans[r][c] = d;

            if (r > 0 && mat[r-1][c] && !visited[r-1][c]) q.push(vector<int>({r-1, c, d+1})), visited[r-1][c] = 1;
            if (c > 0 && mat[r][c-1] && !visited[r][c-1]) q.push(vector<int>({r, c-1, d+1})), visited[r][c-1] = 1;
            if (r < m-1 && mat[r+1][c] && !visited[r+1][c]) q.push(vector<int>({r+1, c, d+1})), visited[r+1][c] = 1;
            if (c < n-1 && mat[r][c+1] && !visited[r][c+1]) q.push(vector<int>({r, c+1, d+1})), visited[r][c+1] = 1; 
        }
        return ans;
    }
};