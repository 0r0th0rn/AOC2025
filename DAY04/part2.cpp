#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int count(vector<string>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	int cnt = 0;
	int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	while (1) {
		vector<pair<int, int>> remove;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '@') {
					int nr = 0;
					for (int k = 0; k < 8; k++) {
						int neighbor_row = i + di[k];
						int neighbor_col = j + dj[k];
						if (neighbor_row >= 0 && neighbor_row < n && neighbor_col >= 0 && neighbor_col < m)
							if (grid[neighbor_row][neighbor_col] == '@')
								nr++;
					}
					if (nr < 4)
						remove.push_back({ i, j });
				}
			}
		}
		if (remove.empty())
			break;
		cnt += remove.size();
		for (auto p : remove)
			grid[p.first][p.second] = '.';

	}
	return cnt;
}

int main()
{
	vector<string> grid;
	string line;
	while (fin >> line)
		grid.push_back(line);
	fout << count(grid);
	return 0;
}
