#include <iostream>
#include <algorithm>
using namespace std;

int n, l, h, max_pos, max_h;
int arr[1001];
int res = 0;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> h;
        arr[l] = h;
        if (max_h < h) {
          max_pos = l;
          max_h = h;
        }
    }

    int left_max_height=0;
    for (int i = 1; i <max_pos; i++) {
        left_max_height = max(left_max_height, arr[i]);
        res += left_max_height;
    }

    int right_max_height=0;
    for (int i = 1000; i > max_pos; i--) {
        right_max_height = max(right_max_height, arr[i]);
        res += right_max_height;
    }

    cout << res + max_h;
    return 0;
}
