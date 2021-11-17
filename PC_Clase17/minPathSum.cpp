int minPathSum(vector<vector<int>> &grid) {
	
	int row = grid.size(); int col = grid[0].size();
	vector<vector<int>> alma(row, vector<int>(col, 0));
	alma[row - 1][col - 1] = grid[row - 1][col - 1];
	for (int i = row - 2; i >= 0; i--)
		alma[i][col - 1] = grid[i][col - 1] + alma[i + 1][col - 1];

	for (int i = col - 2; i >= 0; i--)
		alma[row - 1][i] = grid[row - 1][i] + alma[row - 1][i + 1];
	for (int i = row - 2; i >= 0; i--) {
		for (int j = col - 2; j >= 0; j--) {
			alma[i][j] = grid[i][j] + min(alma[i + 1][j], alma[i][j + 1]);
		}
	}

	return alma[0][0];
}