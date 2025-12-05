#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct range {
	long long start;
	long long end;
};

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
	int cnt = 0;
	for (long long id : ids) {
		bool ok = 0;
		for (auto r : ranges) {
			if (id >= r.start && id <= r.end) {
				ok = 1;
				break;
			}
		}
		if (ok == 1)
			cnt++;
	}
	fout << cnt;
	return 0;
}
