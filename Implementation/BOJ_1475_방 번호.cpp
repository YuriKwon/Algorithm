#include <iostream>
#include <string>
using namespace std;

int dat[10];

int main() {
    string s;
    cin >> s;
    int len = s.length();

    for (int i=0; i<len; i++) {
        dat[s[i]-'0']++;
    }
    int sum = dat[6] + dat[9];
    if (sum % 2 == 0) {
        dat[6] = sum / 2;
        dat[9] = 0;
    } else {
        dat[6] = sum / 2 + 1;
        dat[9] = 0;
    }

    int maxV = 0;

    // 여기 for문을 0~9까지 돌려야되는데 0~len으로 돌려서 한참 틀림
    for (int i=0; i<10; i++) {
        if (dat[i] > maxV) {
            maxV = dat[i];
        }
    }
    cout << maxV;
    return 0;
}
