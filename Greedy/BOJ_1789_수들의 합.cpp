#include <iostream>
#include <algorithm>
using namespace std;

long long int s, n, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    int val = 1;

    while (s - val > val) {
        s -= val;
        cnt++;
        val++;
    }
    cout << cnt + 1;
    return 0;
}