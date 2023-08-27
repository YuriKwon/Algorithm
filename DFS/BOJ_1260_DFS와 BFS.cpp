#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, V;
int arr[1001][1001];
int path[1001];
int visited[1001];

void init() {
  cin >> N  >> M >> V;
  for (int m=0; m<M; m++) {
    int n1, n2;
    cin >> n1 >> n2;
    arr[n1][n2] = 1;
    arr[n2][n1] = 1;
  }

}

void DFS(int now) {
  cout << now << " ";
  visited[now] = 1;

  for (int i=1; i<=N; i++) {
    if (visited[i] != 0) continue;
    if (arr[i][now] == 0 && arr[now][i] == 0) continue;
    visited[i] = 1;
    DFS(i);
  }

}

void BFS() {
  queue<int> q;
  q.push(V);
  int cnt = 0;
  visited[V] = 1;

  while(!q.empty()) {
    int front = q.front();
    cout << front << " ";
    q.pop();

    for (int i=1; i<=N; i++) {
      if (visited[i] != 0) continue;
      if (arr[i][front] == 0 && arr[front][i] == 0) continue;
      q.push(i);
      cnt++;
      visited[i] = 1;
    }
  }
}

int main() {

  init();
  DFS(V);
  // visited, path 초기화
  memset(visited, 0, sizeof(visited));
  memset(path, 0, sizeof(path));
  cout << endl;
  BFS();
  return 0;
}
