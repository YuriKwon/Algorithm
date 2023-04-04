#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, t;
int arr[15][15]; // 0: 빈공간, 1: 베이스캠프
int unableMove[15][15]; // 1이면 이동 불가 지점
int visited[15][15]; // BFS 체크 목적
int dist[15][15];
bool arrived[30]; // i번째 사람이 편의점에 도착했으면 true

struct Node{
    int y, x;
};
vector<Node> stores;
vector<Node> people; // 사람 현재 위치
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
queue<Node> q;

void input() {
    cin >> n >> m;
    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            cin >> arr[y][x];
        }
    }

    for (int i=0; i<m; i++) {
        int y, x;
        cin >> y >> x;
        people.push_back({0, 0});
        stores.push_back({y-1, x-1}); // 0부터 시작하기 때문에 -1 처리
    }
}

Node findNearBasecamp(int seq) { // seq: 몇번 사람인지
    // visited 초기화
    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            visited[y][x] = 0;
        }
    }

    Node targetStore = stores[seq]; // 목표 편의점
    // targetStore에서 BFS 돌려서 가장 가까운 base 캠프 찾기.
    // 거리 같으면 행 작은 순, 열 작은순으로 갱신
    q.push(targetStore);
    int distanceToBasecamp = 99999; // 편의점~베이스캠프까지의 최소 거리
    Node Basecamp;
    while(!q.empty()) {
        Node cur = q.front(); // 목표 편의점에서 가까운 베이스 캠프 찾기
        // 현재 위치가 베이스캠프이면
        if (arr[cur.y][cur.x] == 1) {
            int dist = visited[cur.y][cur.x];
            // 새로운 최단 거리인 경우
            if (dist < distanceToBasecamp) {
                distanceToBasecamp = dist;
                Basecamp = cur;
            }
            // 기존 최단거리랑 같으면, 행, 열 작은걸로 갱신
            else if (dist == distanceToBasecamp) {
                if (Basecamp.y > cur.y) {
                    Basecamp = cur;
                } else if (Basecamp.y == cur.y && Basecamp.x > cur.x) {
                    Basecamp = cur;
                }
            }
        }
        q.pop();
        // 다음 탐색 지점 넣기
        for (int i=0; i<4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx] > 0 || unableMove[ny][nx] == 1) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[cur.y][cur.x] + 1; // 1 더하는 이유 - 이동 최단거리 파악하려고
        }

    }
    return Basecamp;
}

void movePerson(int seq) { // seq: 몇번 사람인지
    // dist 초기화
    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            dist[y][x] = 0;
        }
    }

    Node targetStore = stores[seq]; // 목표 편의점
    // 편의점에서 모든 지점까지의 최단거리 구해서 dist 배열에 저장
    // TODO: BFS - 모듈화
    q.push(targetStore);
    dist[targetStore.y][targetStore.x] = 1;
    while(!q.empty()) {
        Node cur = q.front();
        q.pop();
        // 다음 탐색 지점 넣기
        for (int i=0; i<4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (dist[ny][nx] > 0 || unableMove[ny][nx] == 1) continue;
            q.push({ny, nx});
            dist[ny][nx] = dist[cur.y][cur.x] + 1; // 1 더하는 이유 - 이동 최단거리 파악하려고
        }
    }

    // 현재 사용자의 위치에서 4방향 중 dist값이 가장 작은 곳(이동 가능 시)으로 이동
    int maxDist = 99999;
    int direction = 0;
    Node peopleLocation = people[seq];

    for (int i=0; i<4; i++) {
        int ny = peopleLocation.y + dy[i];
        int nx = peopleLocation.x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

        if (dist[ny][nx] != 0 && dist[ny][nx] < maxDist) {
            direction = i;
            maxDist = dist[ny][nx];
        }
    }
    people[seq].y = peopleLocation.y + dy[direction];
    people[seq].x = peopleLocation.x + dx[direction];
    return;
}


int main() {
    input();
    while(true) {
        bool allArrived = true; // 모든 사람이 도착했으면 true
        for (int i=0; i<m; i++) {
            if (!arrived[i]) allArrived = false;
        }
        if (allArrived) {
            cout << t;
            break;
        }
        for (int i=0; i<m; i++) { // 사람 하나하나 이동
            // i 번째 사람이 이미 편의점에 도착했으면, 그 사람은 검사하지 않고 넘기기 continue
            if (arrived[i]) continue;
            if (t == i) {
                // 좌표에 처음으로 들어감. 베이스캠프로
                // 이동 가능베이스 캠프를 찾고, 거기 unableMove=1로 변경
                Node Basecamp = findNearBasecamp(i); // 베이스캠프부터 구하기
                unableMove[Basecamp.y][Basecamp.x] = 1;
                people[i] = {Basecamp.y, Basecamp.x};
            } else if (t < i) {
                // 0초인데 2번째 사람 -> 아직 이동 X
                break;
            } else if (t > i) {
                // 3초인데 1번째 사람
                movePerson(i);
                // DFS가 아닌데 최단거리 저장은 어떻게..?
                /*
                해설에서는, 내 위치에서 편의점까지 최단거리를 구하는게 아니라
                편의점에서 모든 격자의 최단거리를 구하고.. 그 값이 더 작은 지점 쪽으로 이동하는거라고 한다.
                // 출처는 https://colorscripter.com/s/8Wmf0ED
                */

                // 2 - 편의점 도착 시, 멈춤
                Node store = stores[i];
                if (people[i].y == store.y && people[i].x == store.x) {
                    unableMove[store.y][store.x] = 1;
                    arrived[i] = true;
                    continue;
                }
            }
        }
        t++;
    }

    return 0;
}
