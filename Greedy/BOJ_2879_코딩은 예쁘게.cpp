#include <iostream>
#include <algorithm>
using namespace std;

int n;
int nowTab[1001];
int targetTab[1001];
int _move[1001];
int sign; //부호: 1이면 양수, -1이면 음수, 0이면 0
int last; // 영역의 마지막 인덱스
int cnt;

int getSign(int n) {
    int sign;

    if (n > 0) sign = 1;
    else if (n < 0) sign = -1;
    else sign = 0;

    return sign;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nowTab[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> targetTab[i];
    }
    for (int i = 0; i < n; i++) {
        _move[i] = targetTab[i] - nowTab[i]; // 이동해야 하는 탭의 방향 + 횟수
    }

    for (int i = 0; i < n; i++) {
        // 현재 값이 0이면 작업 수행X 
        while (_move[i] != 0) {
            sign = getSign(_move[i]);
            for (int j = i + 1; j <= n; j++) {
                int sign2 = getSign(_move[j]);
                if (sign == sign2) continue;
                else {
                    last = j - 1;
                    break;
                }

            }
            // i부터 last위치까지 더한다
            for (int k = i; k <= last; k++) {
                if (_move[k] == 0) break;
                if (sign == 1) _move[k] -= 1;
                else if (sign == -1) _move[k] += 1;
                
            }
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}