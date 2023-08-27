#include <iostream>
#include <queue>
using namespace std;

// struct Node {
//   int y, x;
// };
queue<int> q;
int N, num1, num2, M;
int arr[101][101];
int visited[101];

void BFS() {
  while(!q.empty()) {
    int top = q.front();
    q.pop();

    for (int i=1; i<=N; i++) {
      if (visited[i] != 0) continue;
      if (arr[i][top] == 0 && arr[top][i] == 0) continue;
      q.push(i);
      visited[i] = visited[top] + 1;
    }

  }
  return;
}

void init() {
  cin >> N;
  cin >> num1 >> num2;
  cin >> M;
  for (int m=0; m<M; m++) {
    int n1, n2;
    cin >> n1 >> n2;
    arr[n1][n2] = 1;
  }
}

int main() {
  init();
  q.push(num1);
  visited[num1] = 1;
  BFS();
  cout << visited[num2] -1;

}
