#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool repeated(long long n) {
    string s = to_string(n);
    int k = s.length();
    for (int i = 1; i <= k / 2; i++) {
        if (k % i == 0) {
            string pattern = s.substr(0, i);
            bool ok = true;
            for (int j = i; j < k; j += i) {
                if (s.substr(j, i) != pattern) {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                return true;
        }
    }
    return false;
}

int main() {
    string s;
    getline(fin, s);
    stringstream ss(s);
    string segment;
    long long sum = 0;
    while (getline(ss, segment, ',')) {
        int dash_pos = segment.find('-');
        long long start = stoll(segment.substr(0, dash_pos));
        long long end = stoll(segment.substr(dash_pos + 1));
        for (long long i = start; i <= end; i++)
            if (repeated(i))
                sum += i;
    }
    fout << sum;
    return 0;
}
