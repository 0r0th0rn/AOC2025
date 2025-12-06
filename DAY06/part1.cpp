#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

long long solve_tower(const vector<string>& lines, int start_col, int end_col) {
    vector<long long> numbers;
    char operation = ' ';
    for (int i = 0; i < lines.size(); ++i) {
        string segment = lines[i].substr(start_col, end_col - start_col + 1);
        string token = "";
        for (int j = 0; j < segment.length(); ++j)
            if (segment[j] != ' ')
                token += segment[j];
        if (token.empty()) continue;
        if (token.find('+') != string::npos)
            operation = '+';
        else if (token.find('*') != string::npos)
            operation = '*';
        else 
            numbers.push_back(stoll(token));
    }
    if (numbers.empty()) return 0;
    long long result = numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
        if (operation == '+') 
            result += numbers[i];
        else if (operation == '*')
            result *= numbers[i];
    }
    return result;
}

int main() {
    vector<string> lines;
    string input_line;
    int max_width = 0;
    while (getline(fin, input_line)) {
        lines.push_back(input_line);
        if (input_line.length() > max_width)
            max_width = input_line.length();
    }
    for (int i = 0; i < lines.size(); ++i)
        lines[i].resize(max_width, ' ');
    long long grand_total = 0;
    int tower_start = -1;
    for (int col = 0; col < max_width; ++col) {
        bool is_separator = true;
        for (int row = 0; row < lines.size(); ++row) {
            if (lines[row][col] != ' ') {
                is_separator = false;
                break;
            }
        }
        if (!is_separator) {
            if (tower_start == -1) {
                tower_start = col;
            }
        }
        else {
            if (tower_start != -1) {
                grand_total += solve_tower(lines, tower_start, col - 1);
                tower_start = -1;
            }
        }
    }
    if (tower_start != -1)
        grand_total += solve_tower(lines, tower_start, max_width - 1);
    fout << grand_total;
    return 0;
}
