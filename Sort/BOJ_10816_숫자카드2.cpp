#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, m, k, h, y, x;
int main() {

    cin >> t;
    vector<int> v(t);

    for (int i = 0; i < t; i++)
        scanf("%d", &v[i]);

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
