#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool flag = true;
int visited[5][5];
char map[5][5];
vector<pair<int, int>> person; //
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int depth) {
    // depth: 맨허튼거리를 의미함
    if (depth > 2) return;
    if (depth > 0 && map[y][x] == 'P') {
        // 맨허튼 거리 2 이하에서 사람만났으므로 false
        flag = false;
        return;
    }
    visited[y][x] = 1;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >=0 && ny <=4 && nx >=0 && nx <=4 && visited[ny][nx] != 1 && map[ny][nx] != 'X') {
            dfs(ny, nx, depth + 1);
        }
    }
}

int solve() {
    flag = true;
    for (int i=0; i<person.size(); i++) {
        dfs(person[i].first, person[i].second, 0);
        if (!flag) return 0;
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    // cout << places;
    int len = places.size();
    for (int i=0; i<len; i++) {
        person.clear();
        memset(visited, 0, sizeof(visited));
        for (int y=0; y<5; y++) {
            for (int x=0; x<5; x++) {
                map[y][x] = places[i][y][x];
                if (map[y][x] == 'P') {
                    person.push_back({y, x});
                }
            }
        }
        int result = solve();
        answer.push_back(result);
    }
    return answer;
}
