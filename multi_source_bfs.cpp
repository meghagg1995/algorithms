bool check(int x, int y, int m, int n) {
    return x >=0 && y>=0 && x<m && y<n;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int, int> p = q.front();
                q.pop();
                for(int i=0;i<4;i++) {
                    int nx = p.first + dx[i];
                    int ny = p.second + dy[i];
                    if(check(nx, ny, m, n) && mat[nx][ny] == 1) {
                        q.push({nx, ny});
                        mat[nx][ny] = 0;
                        res[nx][ny] = level + 1;
                    }
                }
            }
            level++;
        }
        return res;
    }
};
