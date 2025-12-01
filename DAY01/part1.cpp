#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    string x;
    int poz = 50, cnt = 0;
    while (fin >> x) {
        char direction = x[0];
        int n = stoi(x.substr(1));
        n = n % 100;
        if (direction == 'R') {
            poz = poz + n;
            if (poz > 99)
                poz -= 100;
        }
        else if (direction == 'L') {
            poz = poz - n;
            if (poz < 0)
                poz += 100;
        }
        if (poz == 0)
            cnt++;
    }
    fout << cnt;
    return 0;
}
