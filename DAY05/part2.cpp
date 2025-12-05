#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct range {
	long long start;
	long long end;
};

bool compare(range a, range b) {
	return a.start < b.start;
}

int main()
{
	string line;
	vector<range> ranges;
	vector<long long> ids;
	while (getline(fin, line)) {
		if (line.empty())
			continue;
		if (line.find('-')!=string::npos) {
			long long start, end;
			char dash;
			stringstream ss(line);
			ss >> start >> dash >> end;
			ranges.push_back({ start, end });
		}
		else {
			long long id = stoll(line);
			ids.push_back(id);
		}
	}
	sort(ranges.begin(), ranges.end(), compare);
	long long cnt = 0;
	long long curr_start = ranges[0].start;
	long long curr_end = ranges[0].end;
	long long n = ranges.size();
	for (int i = 1; i < n; i++) {
		if (ranges[i].start <= curr_end)
			curr_end = max(curr_end, ranges[i].end);
		else {
			cnt += (curr_end - curr_start + 1);
			curr_start = ranges[i].start;
			curr_end = ranges[i].end;
		}
	}
	cnt += (curr_end - curr_start + 1);
	fout << cnt;
	return 0;
}
