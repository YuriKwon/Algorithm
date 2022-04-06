#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int n, arrlen, sum;
int frequency[200];
int num = 9; // 숫자 할당

struct Node {
    char alpha;
    int freq;
};
Node arr[10];

int compare(Node a, Node b){
    return a.freq > b.freq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    // string 입력받고, 나온 빈도 계산하는 부분
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            // 자릿수도 제곱으로 환산해서 더해주기
            frequency[s[i]] += pow(10, len - i - 1);
        }
    }

    // 빈도에 따른 알파벳 정렬
    for (int i = 0; i < 200; i++) {
        if (frequency[i] != 0) {
            arr[arrlen].alpha = (char)i;
            arr[arrlen].freq = frequency[i];
            arrlen++;
        }
    }
    sort(arr, arr + arrlen, compare);

    for (int i = 0; i < arrlen; i++) {
        sum += arr[i].freq * num;
        num--;
    }

    cout << sum;

    return 0;
}