#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    int idx = 0;
    string ans = "";

    while(true) {
        if (idx >= s.length()) break;
        if (s[idx] == 'z') {
            idx += 4;
            ans += '0';
        } else if (s[idx] =='o') {
            idx += 3;
            ans += '1';
        } else if (s[idx] =='t') {
            if (s[idx + 1] == 'w') {
                idx += 3; // two
                ans += '2';
            } else {
                idx += 5; // three
                ans += '3';
            }
        } else if (s[idx] =='f') {
            if (s[idx+1] == 'o') {
                idx += 4;
                ans += '4';
            } else {
                idx += 4;
                ans += '5';
            }
        } else if (s[idx] =='s') {
            if (s[idx+1] == 'i') {
                idx += 3;
                ans += '6';
            } else {
                idx += 5;
                ans += '7';
            }
        } else if (s[idx] =='e') {
            idx += 5;
            ans += '8';
        } else if (s[idx] =='n') {
            idx += 4;
            ans += '9';
        } else {
            ans += s[idx];
            idx += 1;
        }

    }
    return stoi(ans);;
}

/*
너무 일차원적으로 푼것 같다. 다른 사람 코드를 보니까 <regex> 라이브러리를 사용해서
s = regex_replace(s, regex("one"), 1);
s = regex_replace(s, regex("two"), 2);
...
이런 식으로 엄청 간단하게 풀 수 있다는 걸 배웠다.
*/
