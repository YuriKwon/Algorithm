#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());

    // 가장 긴 변 선택하기
    for (int i = 0; i < n; i++) {
        if (i == n - 2) {
            cout << -1;
            break;
        }
        if (arr[i] < (arr[i + 1] + arr[i + 2])) {
            cout << arr[i] + arr[i + 1] + arr[i + 2];
            break;
        }
    }

    return 0;
}