#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool repeated(long long n) {
    string s = to_string(n);
    if (s.length() % 2 == 1)
        return false;
    int mid = s.length() / 2;
    return s.substr(0, mid) == s.substr(mid);
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
