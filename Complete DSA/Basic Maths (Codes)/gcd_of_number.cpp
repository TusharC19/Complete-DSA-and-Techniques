# include <bits/stdc++.h>
using namespace std;

int gcdNum(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a = 3, b = 7;
    cout << gcdNum(a, b) << endl;
    return 0;
}