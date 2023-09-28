#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int N, M, K;
int map[11][11];
int backup[11][11];
struct Node{
    int y, x;
    bool isOut;
};
Node people[11];
Node backupPeople[11];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int rectY, rectX, rectSize;
int moveCnt; // answer
int outY, outX; // 출구

void printArr() {
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cout << map[y][x] << " ";
        }
        cout << endl;
    }
}

void printP() {
    for (int i=0; i<M; i++) {
    Node person = people[i];
    cout << person.y << " " << person.x << " " << person.isOut << endl;
    }
}

// 모든 참가자 이동
void move() {
    // isOut = false인 참가자만 이동

    for (int i=0; i<M; i++) {
        Node person = people[i];
        if (person.isOut == true) continue;
        // bool isMovedcurrentPerson = false;

        // next 위치 선정
        for (int j=0; j<4; j++) {
            int ny = person.y + dy[j];
            int nx = person.x + dx[j];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            // 벽이면 이동 X
            if (map[ny][nx] > 0) continue;
            // 현재 위치~ 출구까지의 거리
            int currDistance = abs(outY - person.y) + abs(outX - person.x);
            int nextDistance = abs(outY - ny) + abs(outX - nx);

            if (currDistance <= nextDistance) continue;

            // 위의 조건을 전부 만족했다면, 이동 후 다음 사람으로,,
            people[i].y = ny;
            people[i].x = nx;
            moveCnt++;

            // 출구면, out 처리
            if (ny == outY && nx == outX) {
                people[i].isOut = true;
            }
            break;
        }
    }
}

void findRect() {
    for (int size = 2; size <= N; size++) {
        for (int y=0; y<=N-size; y++) {
            for (int x=0; x<=N-size; x++) {
                // 사각형의 좌상단 점: (y, x)
                // 현재 사각형에서 출구, 참가자가 나왔는지 여부
                bool isOut = false;
                bool isPerson = false;
                // 사각형 내부 검사
                for (int j=0; j<size; j++) {
                    for (int k=0; k<size; k++) {
                        // 출구인지 판별
                        if (y+j == outY && x+k == outX) isOut = true;
                        // 사람인지 판별
                        for (int i=0; i<M; i++) {
                            Node person = people[i];
                            if (person.isOut == true) continue;
                            if (y+j == person.y && x+k == person.x) {
                                isPerson = true;
                                break;
                            }
                        }
                    }
                }
                if (isOut && isPerson) {
                    rectY = y;
                    rectX = x;
                    rectSize = size;
                    return; // 함수 자체를 종료
                }
            }
        }
    }
}

void rotate() {
    int newOutY, newOutX;
    // 배열 회전 + 출구 회전
    memcpy(backup, map, sizeof(map)); // map을 백업배열에 저장

    for (int y=0; y<rectSize; y++) {
        for (int x=0; x<rectSize; x++) {
            int prevVal = backup[rectY + y][rectX + x];
            map[rectY + x][rectX + rectSize-y-1] = prevVal;

            if (y + rectY == outY && x + rectX == outX) {
                newOutY = rectY + x;
                newOutX = rectX + rectSize-1 -y;
            }
        }
    }

    outY = newOutY;
    outX = newOutX;


    // 사각형 안에 있는 사람 회전 + // 내구도 감소
    memcpy(backupPeople, people, sizeof(people));
    for (int y=0; y<rectSize; y++) {
        for (int x=0; x<rectSize; x++) {
            if (map[rectY + y][rectX + x] > 0) map[rectY + y][rectX + x]--;
            for (int i=0; i<M; i++) {
                Node person = backupPeople[i];
                if(person.isOut) continue;
                if (person.y == rectY + y && person.x == rectX + x) {
                    people[i].y = rectY + x;
                    people[i].x = rectX + rectSize-1 -y;
                }
            }

        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cin >> map[y][x];
        }
    }
    for (int i=0; i<M; i++) {
        int y, x;
        cin >> y >> x;

        people[i] = {y-1, x-1, false};
    }
    cin >> outY >> outX;
    outY -= 1;
    outX -= 1;

    int time = 1;
    while(true) {
        if (time > K) break;
        move();

        // 모든사람이 탈출했는지 확인
        bool isAllOut = true;
        for (int i=0; i<M; i++) {
            Node person = people[i];
            if (person.isOut == false) {
                isAllOut = false;
                break;
            }
        }
        if (isAllOut) {
            // 게임 종료
            break;
        }

        findRect();
        rotate();
        time++;
    }
    cout << moveCnt << endl;
    cout << outY + 1 << " " << outX + 1;
    return 0;
}
