vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> spiral;
    int start_row = 0;
    int start_col = 0;
    int end_row = matrix.size()-1;
    int end_col = matrix[0].size()-1;
    int dir = 0;
    while(start_row <= end_row && start_col <= end_col) {
        if(dir == 0) {
            for(int i=start_col;i<=end_col;i++) {
                spiral.push_back(matrix[start_row][i]);
            }
            start_row++;
        }else if(dir == 1) {
            for(int i=start_row;i<=end_row;i++) {
                spiral.push_back(matrix[i][end_col]);
            }
            end_col--;
        }else if(dir == 2) {
            for(int i=end_col;i>=start_col;i--) {
                spiral.push_back(matrix[end_row][i]);
            }
            end_row--;
        }else {
            for(int i=end_row;i>=start_row;i--) {
                spiral.push_back(matrix[i][start_col]);
            }
            start_col++;
        }
        dir = (dir+1)%4;
    }
    return spiral;
}
