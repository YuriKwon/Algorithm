// 무조건.. 단계별로 검증하기..
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
int potab[11][11]; // 포탑의 공격력 저장
int visited[11][11];
int attack[11][11]; // 공격과 연관 있는 포탑이면, 1
int attackTime[11][11]; // 가장 최근에 공격한 숫자를 기억
int attackerY, attackerX, attackTargetY, attackTargetX;
bool isPossibleLaserAttack = false;
// 우, 하, 좌, 상
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
struct Node{
  int y, x;
};
struct Node2{
  int y, x;
  int prev_idx; // 몇번 큐에서 왔는지 저장
};
vector<Node> sortedPotab;

void printPotab() {
  //
  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      cout << potab[y][x] << " ";
    }
    cout << endl;
  }
}

void input() {
  cin >> N >> M >> K;

  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      cin >> potab[y][x];
    }
  }
}



// 0 참조시 공격자, 맨 뒤의 애 참조시 공격 대상
bool compare(Node a, Node b) {
  int attackPoint_A = potab[a.y][a.x];
  int attackPoint_B = potab[b.y][b.x];

  // 공격력 가장 낮은 애 > 가장 최근에 공격한 애 > 행+열 값 가장 큰 애 > 열 값 가장 큰 애
  if (attackPoint_A < attackPoint_B) return true;
  else if (attackPoint_A > attackPoint_B) return false;

  if (attackTime[a.y][a.x] > attackTime[b.y][b.x]) return true;
  else if (attackTime[a.y][a.x] < attackTime[b.y][b.x]) return false;

  if (a.y + a.x > b.y + b.x) return true;
  else if (a.y + a.x < b.y + b.x) return false;

  if (a.x > b.x) return true;
  else if (a.x < b.x) return false;

  return false;
}

void init() {
  // visited 초기화
  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      visited[y][x] = 0;
    }
  }

  // attack[y][x] 초기화
  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      attack[y][x] = 0;
    }
  }

  // 정렬
  sortedPotab.clear();
  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      // 부서진 포탑이 아닌 경우에만, 공격자, 공격 대상으로 삼는다.
      if (potab[y][x]) {
        sortedPotab.push_back({y, x});
      }
    }
  }

  sort(sortedPotab.begin(), sortedPotab.end(), compare); // 공격자, 공격 대상 선정을 위해 포탑을 약한순으로 정렬
}

void setAttacker(int currentTurn) {
  // 가장 약한 포탑 찾고, N+M만큼 공격력 증가
  // 공격력 가장 낮은 애 > 가장 최근에 공격한 애 > 행+열 값 가장 큰 애 > 열 값 가장 큰 애

  // cout << "공격자: ";
  // cout << sortedPotab.front().y << " " << sortedPotab.front().x << endl;
  attackerY = sortedPotab.front().y;
  attackerX = sortedPotab.front().x;
  attackTime[attackerY][attackerX] = currentTurn;

  // N+M만큼 공격력 증가
  potab[attackerY][attackerX] += N+M;

  attack[attackerY][attackerX] = 1;
}

void setAttackTarget() {
  // cout << "공격 대상: ";
  // cout << sortedPotab.back().y << " " << sortedPotab.back().x << endl;

  attackTargetY = sortedPotab.back().y;
  attackTargetX = sortedPotab.back().x;
  attack[attackTargetY][attackTargetX] = 1;
}

void laserAttack() {
  isPossibleLaserAttack = false;
  // 최단 경로 찾았으면, isPossible -> true, return
  // BFS로 공격자 -> 공격 대상 최단경로 찾기

  // 부서진 포탑은 못지남, 벽뚫음
  vector<Node2> queue; // 이전 경로 추적을 위해
  queue.push_back({attackerY, attackerX, 0}); // 시작점
  visited[attackerY][attackerX] = 1;
  int idx = 0;

  while(true) {
    if (queue.size() <= idx) break;
    Node2 cur = queue[idx];

    // 공격 대상에 도달 시
    if (cur.y == attackTargetY && cur.x == attackTargetX) {
      int attackPower = potab[attackerY][attackerX];
      isPossibleLaserAttack = true;

      // 공격력만큼 감소
      potab[attackTargetY][attackTargetX] -= attackPower;

      int prevQueueIdx = cur.prev_idx;
      // 경로에 대해서, 공격력의 절반만큼 감소

      // while문 종료 조건에 대해..
      while(true) {
        prevQueueIdx = cur.prev_idx;

        // 시작점(공격자 위치)에 도달 시, 종료
        if (prevQueueIdx == 0) break;
        cur = queue[prevQueueIdx]; // 이전 위치
        potab[cur.y][cur.x] -= (attackPower / 2);
        attack[cur.y][cur.x] = 1;

        // cout << "이전 위치: ";
        // cout << cur.y << " " << cur.x << endl;
      }
      return;
    }

    // 4방향 탐색 후 넣기
    for (int i=0; i<4; i++) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      if (ny < 0) ny += N;
      if (nx < 0) nx += M;
      if (ny >= N) ny -= N;
      if (nx >= M) nx -= M;

      if (potab[ny][nx] == 0) continue;
      if (visited[ny][nx] == 1) continue;
      visited[ny][nx] = 1;
      queue.push_back({ny, nx, idx});
    }

    idx++;
  }
}

void potanAttack() {
  int attackPower = potab[attackerY][attackerX];

  for (int y=0; y<3; y++) {
    for (int x=0; x<3; x++) {

      int ny = y + attackTargetY - 1;
      int nx = x + attackTargetX - 1;

      if (ny < 0) ny += N;
      if (nx < 0) nx += M;
      if (ny >= N) ny -= N;
      if (nx >= M) nx -= M;

      if (potab[ny][nx] == 0) continue;
      if (ny == attackerY && nx == attackerX) continue;

      attack[ny][nx] = 1;
      // cout << "포탄 공격: " << ny << " " << nx << endl;

      if (ny == attackTargetY && nx == attackTargetX) {
        // 공격력만큼 감소
        potab[ny][nx] -= attackPower;
      } else {
        potab[ny][nx] -= (attackPower / 2);
      }
    }
  }
}

void attackPotab() {
  laserAttack();
  if (!isPossibleLaserAttack) {
    potanAttack();
  }
}

void brokePotab() {
  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      if (potab[y][x] < 0) potab[y][x] = 0;
    }
  }
}

void settingPotab() {
  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      if (potab[y][x] > 0 && attack[y][x] == 0) potab[y][x]+= 1;
    }
  }
}

int main() {
  input();

  for (int turn=1; turn <= K; turn++) {
    // 부서지지 않은 포탑이 1개면, 즉시 중지 하는 로직 필요
    init();

    setAttacker(turn);
    setAttackTarget();

    attackPotab();
    // cout << "게임 이후" << endl;
    // printPotab();
    brokePotab();
    settingPotab();
    // cout << "세팅 이후" << endl;
    // printPotab();
    // cout << " - - - - -" << endl;

    // 부서지지 않은 포탑이 1개면, 즉시 중지 하는 로직 필요 - 여기서?
    int cnt = 0;
    for (int y=0; y<N; y++) {
      for (int x=0; x<M; x++) {
        if (potab[y][x] > 0) cnt++;
      }
    }
    if (cnt == 1) break;
  }

  int ans = 0;
  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      if (potab[y][x] > ans) ans = potab[y][x];
    }
  }
  cout << ans;
  return 0;
}
