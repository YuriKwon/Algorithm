#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, answer;
map<pair<string, string>, int> m;

int main() {
  cin >> n;

  for (int i=0; i<n; i++) {
    string c, s;
    c = c.substr(0, 2);

    if (s == c) continue;

    m[{s, c}]++;
    answer += m[{c, s}];
    cout << answer << '\n';
    return 0;
  }
}
