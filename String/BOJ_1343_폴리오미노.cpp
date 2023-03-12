#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int startIdx, endIdx; // X로 이루어진 문자열의 시작점, 끝점
struct Node{
  int start, end;
};
vector<Node> v;
char arr[51];

int main() {
  cin >> s;
  int sLen = s.length();
  for (int i=0; i<sLen; i++) {
    arr[i] = '.';
  }
  for (int i = 0; i < sLen; i++) {
    if (s[i] == 'X' && i == 0) {
      startIdx = i;
    } else if (i > 0 && s[i] == 'X' && s[i-1] == '.') {
      startIdx = i;
    } else if (i > 0 && s[i] == '.' && s[i-1] == 'X') {
      endIdx = i - 1;
      v.push_back({startIdx, endIdx});
    }
    if (i == sLen - 1 && s[i] == 'X') {
      endIdx = i;
      v.push_back({startIdx, endIdx});
    }
  }
  for (int i=0; i<v.size(); i++) {
    int len = v[i].end - v[i].start + 1;
    if (len % 2 == 1) {
      cout << "-1";
      return 0;
    }
  }

  for (int idx=0; idx<v.size(); idx++) {
    int len = v[idx].end - v[idx].start + 1;
    int num1 = len / 4;
    int num2 = len % 4;

    for (int i=0; i<=num1; i++) {
      if (i < num1) {
        for (int j=0; j<4; j++) {
          arr[(i * 4) + v[idx].start + j] = 'A';
        }
      } else {
        for (int j=0; j<num2; j++) {
          arr[(i * 4) + v[idx].start + j] = 'B';
        }
      }

    }
  // cout << v[i].start << ' ' << v[i].end << '\n';
  }
  for (int i=0; i<sLen; i++) {
    cout << arr[i];
  }

  return 0;
}
