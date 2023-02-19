#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int visited[100001];
struct Node {
  int val, time;
};

queue<Node> q;

void BFS() {
  while(!q.empty()) {
    Node cur = q.front();
    visited[cur.val] = 1;
    if (cur.val == k) {
      cout << cur.time;
      return;
    }
    q.pop();
    // visited 체크 -> 메모리 초과 방지, 영역 체크 -> 런타임에러 OutOfBounds 방지
    if (cur.val - 1 >= 0 && visited[cur.val - 1] == 0) {
      q.push({val: cur.val - 1, time: cur.time + 1});
    }
    if (cur.val + 1 <= 100000 && visited[cur.val + 1] == 0) {
      q.push({val: cur.val + 1, time: cur.time + 1});
    }
    if (cur.val * 2 <= 100000 && visited[cur.val * 2] == 0) {
      q.push({val: cur.val * 2, time: cur.time + 1});
    }
  }
}

int main() {
  cin >> n >> k;
  q.push({val: n, time: 0});
  BFS();
  return 0;
}
