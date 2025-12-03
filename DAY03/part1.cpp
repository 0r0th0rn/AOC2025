#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	string s;
	long long sum = 0;
	while (getline(fin, s)) {
		int n = s.length();
		int max1 = -1, max2 = -1, maxmax = 0, poz = 0;
		for (int i = 0; i < n; i++) {
			int c = s[i] - '0';
			if (c > max1) {
				max1 = c;
				poz = i;
			}
		}
		if (poz != n - 1) {
			for (int i = poz + 1; i < n; i++) {
				int c = s[i] - '0';
				if (c > max2) {
					max2 = c;
				}
			}
			maxmax = max1 * 10 + max2;
		}
		else {
			for (int i = 0; i < poz; i++) {
				int c = s[i] - '0';
				if (c > max2) {
					max2 = c;
				}
			}
			maxmax = max2 * 10 + max1;
		}
		sum += maxmax;
	}
	fout << sum;
	return 0;
}
