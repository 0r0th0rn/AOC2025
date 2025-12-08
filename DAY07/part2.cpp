#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    vector<string> grid;
    string s;
    while (getline(fin, s)) {
        grid.push_back(s);
    }

    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();

    vector<vector<long long>> dp(n, vector<long long>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] > 0) {
                if (grid[i + 1][j] == '^') {
                    if (j - 1 >= 0) dp[i + 1][j - 1] += dp[i][j];
                    if (j + 1 < m) dp[i + 1][j + 1] += dp[i][j];
                }
                else {
                    dp[i + 1][j] += dp[i][j];
                }
            }
        }
    }

    long long total = 0;
    for (int j = 0; j < m; j++) {
        total += dp[n - 1][j];
    }

    fout << total;
    return 0;
}
