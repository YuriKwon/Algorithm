#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, virusCnt;
int answer = 21e8;
int arr[51][51];
int visited[51][51];
struct Node{
  int y, x;
};

vector<Node> virus;
Node selectedVirus[10];
queue<Node> q;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void init() {
  cin >> N >> M;
  for (int y=0; y<N; y++) {
    for (int x=0; x<N; x++) {
      cin >> arr[y][x];

      // 바이러스 위치 저장
      if (arr[y][x] == 2) {
        virus.push_back({y,x});
      }
    }
  }

}

// 다 퍼트린 최소시간 리턴
int BFS() {
  int time = 0;

  while(!q.empty()) {
    Node front = q.front();

    q.pop();
    for (int i=0; i<4; i++) {
      int ny = front.y + dy[i];
      int nx = front.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (visited[ny][nx] != 0) continue;
      if (arr[ny][nx] == 1) continue; // 벽

      q.push({ny, nx});
      visited[ny][nx] = visited[front.y][front.x] + 1;


    }
  }

  // 모든 빈칸에 바이러스를 퍼뜨렸으면 true
  bool isSuccess = true;
  for (int y=0; y<N; y++) {
    for (int x=0; x<N; x++) {
      // visited 배열에서 가장 큰 숫자 -> 다 퍼트리는데 걸린 시간
      if (arr[y][x] != 2) {
        time = max(time, visited[y][x]);
      }

      if (arr[y][x] == 0 && visited[y][x] == 0) {
        // 못퍼뜨린 구간이 있음
        return -1;
      }
    }
  }
  return time == 0 ? time : time - 1;
}

void selectActiveVirus(int level, int cur) {
  if (level == M) {
    // q 비우기
    while (!q.empty()) {
      q.pop();
    }

    // visited 0으로 초기화
    for (int y=0; y<N; y++) {
      for (int x=0; x<N; x++) {
        visited[y][x] = 0;
      }
    }

    for (int i=0; i<M; i++) {
      q.push({selectedVirus[i].y, selectedVirus[i].x});
      visited[selectedVirus[i].y][selectedVirus[i].x] = 1;
    }

    int ret = BFS();
    if (ret != -1) {
      answer = min(ret, answer);
    }

    return;
  }

  for (int i=cur; i<virusCnt; i++) {
    selectedVirus[level] = virus[i];
    selectActiveVirus(level+1, i+1);
  }
}

int main() {
  init();

  virusCnt = virus.size();
  // virusCnt 중에서 m개의 조합을 선택해서, BFS!
  selectActiveVirus(0, 0);

  if (answer == 21e8) cout << -1;
  else cout << answer;

  return 0;

}
