#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int direct[4][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1
};
int used[100][100];
queue<pair<int, int>> q;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            used[i][j] = 0;
        }
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (used[y][x] == 1) continue;
            if (picture[y][x] == 0) continue;

            number_of_area++;
            int flag = picture[y][x];
            int size = 0;
            used[y][x] = 1;
            q.push({y, x});
            size++;

            while(!q.empty()) {
                auto now = q.front();
                q.pop();
                for (int i=0; i<4; i++) {
                    int ny = now.first + direct[i][0];
                    int nx = now.second + direct[i][1];

                    if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
                    if (picture[ny][nx] != flag) continue;
                    if (used[ny][nx] != 0) continue;
                    used[ny][nx] = 1;
                    q.push({ny, nx});
                    size++;
                }
            }
            if (size >= max_size_of_one_area) max_size_of_one_area = size;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
