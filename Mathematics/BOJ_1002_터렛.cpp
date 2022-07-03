#include <iostream>
#include <cmath>
using namespace std;

// y1으로 작성했다가 에러나서 y_1으로 바꿈
int x1, y_1, r1, x2, y2, r2;

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> x1 >> y_1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt((y2-y_1)*(y2-y_1) + (x2-x1)*(x2-x1));

        int l_r = max(r1, r2);
        int s_r = min(r1, r2);
        int sum = l_r + s_r;
        int diff = l_r - s_r;

        if (y2== y_1 && x2 == x1 && r2 == r1) {
            cout << -1;
        } else if (sum < d || diff > d) {
            cout << 0;
        } else if (sum == d || diff == d) {
            cout << 1;
        } else if (diff < d && d < sum) {
            cout << 2;
        }
        cout << '\n';
    }

    return 0;
}
