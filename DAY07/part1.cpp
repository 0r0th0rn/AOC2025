#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    vector<string> a;
    string s;
    while (getline(fin, s))
        a.push_back(s);
    int n = a.size();
    int m = a[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S')
                a[i + 1][j] = '|';
            else if (a[i][j] == '|') {
                int k = i + 1;
                while (k < n && a[k][j] == '.') {
                    a[k][j] = '|';
                    k++;
                }
            }
            else if (a[i][j] == '^' && a[i-1][j]=='|') {
                a[i][j - 1] = '|';
                a[i][j + 1] = '|';
                if (a[i + 1][j - 1] == '.')
                    a[i + 1][j - 1] = '|';
                if (a[i + 1][j + 1] == '.')
                    a[i + 1][j + 1] = '|';
                cnt++;
            }
        }
    }
    fout << cnt;
    return 0;
}
