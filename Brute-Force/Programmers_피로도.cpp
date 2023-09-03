#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer;
int dungeonsCnt;
int path[9];
vector<vector<int>> d;

void DFS(int level, int curK) {
    answer = max(level, answer);
    
    if (level == dungeonsCnt) return;

    for (int i=0; i<dungeonsCnt; i++) {
        if (path[i] == 1) continue;
        if (curK < d[i][0]) continue; // 최소 필요 피로도보다 작은 경우
        path[i] = 1;
        DFS(level+1, curK - d[i][1]);
        path[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeonsCnt = dungeons.size();
    d = dungeons;

    DFS(0, k);

    return answer;
}
