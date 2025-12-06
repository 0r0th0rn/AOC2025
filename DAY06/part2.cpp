#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

long long solve_block(const vector<string>& lines, int start_col, int end_col) {
    vector<long long> numbers;
    char operation = ' ';
    for (int col = end_col; col >= start_col; --col) {
        string num_str = "";
        for (int row = 0; row < lines.size(); ++row) {
            char c = lines[row][col];
            if (isdigit(c))
                num_str += c;
            else if (c == '+' || c == '*')
                operation = c;
        }
        if (!num_str.empty())
            numbers.push_back(stoll(num_str));
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
    int block_start = -1;
    for (int col = 0; col < max_width; ++col) {
        bool is_separator = true;
        for (int row = 0; row < lines.size(); ++row) {
            if (lines[row][col] != ' ') {
                is_separator = false;
                break;
            }
        }
        if (!is_separator) {
            if (block_start == -1) {
                block_start = col;
            }
        }
        else {
            if (block_start != -1) {
                grand_total += solve_block(lines, block_start, col - 1);
                block_start = -1;
            }
        }
    }
    if (block_start != -1)
        grand_total += solve_block(lines, block_start, max_width - 1);
    fout << grand_total;
    return 0;
}
