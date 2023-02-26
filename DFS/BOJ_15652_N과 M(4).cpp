#include <iostream>
using namespace std;

int n, m;
int path[10];

void dfs(int level) {
  if (level > m) {
    for (int i = 1; i <= m; i++) {
      cout << path[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (path[level - 1] <= i) {
      path[level] = i;
      dfs(level + 1);
      path[level] = 0;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    path[1] = i;
    dfs(2);
  }
  return 0;
}
