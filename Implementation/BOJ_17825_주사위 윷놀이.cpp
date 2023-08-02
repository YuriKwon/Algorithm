#include <iostream>
using namespace std;

int dice[10];
int answer, sum;
int malPath[4]; // 각 말이 가고있는 경로의 종류(0~4)
int malPosition[4]; // 현재 말의 위치 기록(인덱스번호)
int path0[100] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 100}; // 22
int path1[100] = {0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40, 100}; // 14
int path2[100] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40, 100}; // 18
int path3[100] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40, 100}; // 24

struct Node {
    int path, position;
};

// 말번호를 입력받아서, 다음 위치값를 구해주는 함수
int getNextPositionNum(int malNum) {
    int curPath = malPath[malNum];
    int curPosition = malPosition[malNum];

    // 도착지점인 경우, 0 리턴
    if (curPath == 0) return (curPosition >= 21) ? 0 : path0[curPosition];
    else if (curPath == 1) return (curPosition >= 13) ? 0 : path1[curPosition];
    else if (curPath == 2) return (curPosition >= 17) ? 0 : path2[curPosition];
    else if (curPath == 3) return (curPosition >= 23) ? 0 : path3[curPosition];
}

// 이동시켜봤을 때, 다른 말과 겹치면 {-1, -1} 리턴
Node moveMal(int malNum, int diceNum) {
    int curPath = malPath[malNum];
    int curPosition = malPosition[malNum];
    int nextPosition = curPosition + diceNum;
    Node ret = {path: -1, position: -1};

    // 일단, 칸이 합류지점에 있는 25~40인경우 경로가 다르더라도 무조건 겹침
    // 중요: 합류지점을 반드시 고려해야함
    // 또 까다로운 점이, 30일때는 겹치는게 아닐수도 있음(합류지점이 아닌 경우)
    if (curPath == 0 && (path0[nextPosition] == 40)) {
        for (int i=0; i<4; i++) {
            if (i == malNum) continue;
            if (path0[nextPosition] == getNextPositionNum(i)) return ret;
        }
    } else if (curPath == 1 && (path1[nextPosition] == 25 || path1[nextPosition] == 30 || path1[nextPosition] == 35 || path1[nextPosition] == 40)) {
        for (int i=0; i<4; i++) {
            if (i == malNum) continue;
            if (malPath[i] == 3 && malPosition[i] == 15) continue;
            if (path1[nextPosition] == getNextPositionNum(i)) return ret;
        }
    } else if (curPath == 2 && (path2[nextPosition] == 25 || path2[nextPosition] == 30 || path2[nextPosition] == 35 || path2[nextPosition] == 40)) {
        for (int i=0; i<4; i++) {
            if (i == malNum) continue;
            if (malPath[i] == 3 && malPosition[i] == 15) continue;
            if (path2[nextPosition] == getNextPositionNum(i)) return ret;
        }
    } else if (curPath == 3 && (path3[nextPosition] == 25 || path3[nextPosition] == 30 || path3[nextPosition] == 35 || path3[nextPosition] == 40)) {
        for (int i=0; i<4; i++) {
            if (i == malNum) continue;
            if (malPath[i] == 3 && malPosition[i] == 15) continue;
            if (nextPosition == 15) continue;
            if (path3[nextPosition] == getNextPositionNum(i)) return ret;
        }
    }

    // 도착지점을 넘어서는 경우, 곧바로 도착지점 리턴
    if (curPath == 0 && nextPosition >= 21) {
        return {path: curPath, position: 21};
    } else if (curPath == 1 && nextPosition >= 13) {
        return {path: curPath, position: 13};
    } else if (curPath == 2 && nextPosition >= 17) {
        return {path: curPath, position: 17};
    } else if (curPath == 3 && nextPosition >= 23) {
        return {path: curPath, position: 23};
    }

    // 만약에, curPath = 0이고, 이동했을때 10이나 20이나 30이고 인덱스도 일치하면 path 변경
    if (curPath == 0 && path0[nextPosition] == 10) {
        for (int i=0; i<4; i++) {
            if (i == malNum) continue;
            // path1을 쓰고 nextPosition이 같은게 있는지 검사
            if (malPosition[i] == nextPosition && malPath[i] == 1) return ret;
        }
        ret.position = nextPosition;
        ret.path = 1;
    } else if (curPath == 0 && path0[nextPosition] == 20) {
        for (int i=0; i<4; i++) {
            if (i == malNum) continue;
            // path2을 쓰고 nextPosition이 같은게 있는지 검사
            if (malPosition[i] == nextPosition && malPath[i] == 2) return ret;
        }
        ret.position = nextPosition;
        ret.path = 2;
    } else if (curPath == 0 && path0[nextPosition] == 30) {
        for (int i=0; i<4; i++) {
            if (i == malNum) continue;
            // path3을 쓰고 nextPosition이 같은게 있는지 검사
            if (malPosition[i] == nextPosition && malPath[i] == 3) return ret;
        }
        ret.position = nextPosition;
        ret.path = 3;
    } else {
        for (int i=0; i<4; i++) {
            if (i == malNum) continue;
            if (malPosition[i] == nextPosition && malPath[i] == curPath) return ret;
        }
        ret.position = nextPosition;
        ret.path = curPath;
    }

    return ret;
}

void dfs(int turn, int sum) {
    if (turn == 10) {
        // answer를 최대값으로 갱신
        answer = max(answer, sum);
        return;
    }

    for (int i=0; i<4; i++) {
        int curPath = malPath[i];
        int curPosition = malPosition[i];

        // 만약 i번째 말이 이미 도착했다면 continue
        if (curPath == 0 && curPosition >= 21) {
            continue;
        } else if (curPath == 1 && curPosition >= 13) {
            continue;
        } else if (curPath == 2 && curPosition >= 17) {
            continue;
        } else if (curPath == 3 && curPosition >= 23) {
            continue;
        }

        // 만약 i번째 말을 선택해서 이동했는데, 그 위치에 다른 말이 존재한다면 continue (도착인 경우는 예외)
        Node afterMove = moveMal(i, dice[turn]);
        int positionAfterMove = afterMove.position;
        int pathAfterMove = afterMove.path;
        if (positionAfterMove == -1) continue;

        // 갈 수 있다면, 이동
        malPosition[i] = positionAfterMove;
        malPath[i] = pathAfterMove;
        // 다음에 이동시킬 말을 선택해서 dice[turn]만큼 이동시켰을때의 숫자값
        int nextPositionNum = getNextPositionNum(i);

        dfs(turn+1, sum + nextPositionNum);
        malPosition[i] = curPosition;
        malPath[i] = curPath;
    }
}

int main() {
    for (int i=0; i<10; i++) {
        cin >> dice[i];
    }

    dfs(0, 0);

    cout << answer;

    return 0;
}
