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
		int target = 12;
		int start = 0;
		string nr="";
		while (target > 0) {
			int max1 = -1;
			int poz = -1;
			for (int i = start; i < n-target+1; i++) {
				int c = s[i] - '0';
				if (c > max1) {
					max1 = c;
					poz = i;
				}
			}
			if (poz != -1) {
				nr += s[poz];
				start = poz + 1;
				target--;
			}
		}
		sum += stoll(nr);
	}
	fout << sum;
	return 0;
}
