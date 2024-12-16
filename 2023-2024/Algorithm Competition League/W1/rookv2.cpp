#include <iostream>
using namespace std;

long long derangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;

    long long prevPrev = 1, prev = 0, current = 0;

    for (int i = 2; i <= n; ++i) {
        current = (i - 1) * (prev + prevPrev);
        prevPrev = prev;
        prev = current;
    }

    return current;
}

int main() {
    for (int n = 1; n <= 10; ++n) {
        cout << "n = " << n << ": " << derangement(n) << endl;
    }
    return 0;
}
