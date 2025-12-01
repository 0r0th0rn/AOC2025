#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    string x;
    int poz = 50; 
    long long cnt = 0;
    while (fin >> x) {
        char direction = x[0];
        int n = stoi(x.substr(1));
        cnt += n / 100;  
        n = n % 100;
        if (direction == 'R') {
            poz = poz + n;
            if (poz >= 100) {
                cnt++;
                poz -= 100;
            }
        }
        else if (direction == 'L') {
            if (poz != 0 && (poz - n <= 0)) {
                cnt++;
            }
            poz = poz - n;
            if (poz < 0) {
                poz += 100;
            }
        }
    }
    fout << cnt;
    return 0;
}
