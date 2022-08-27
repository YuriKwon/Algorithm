// 너무 느림.. 다시 해보자
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, num, n, m, k, x, y;

int main() {
    cin >> t;
    vector<int> v(t);

    for (int i = 0; i < t; i++) {
        cin >> num;
        v[i] = num;
    }

    sort(v.begin(), v.end());
    cin >> t;

    vector<int> answer(t);
    for (int i = 0; i < t; i++) {
        cin >> k;
        auto upper = upper_bound(v.begin(), v.end(), k);
        auto lower = lower_bound(v.begin(), v.end(), k);

        answer[i] = upper - lower;
    }

    for (auto n : answer)
        cout << n << " ";

    return 0;
}
