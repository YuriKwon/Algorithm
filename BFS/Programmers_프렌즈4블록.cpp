#include <string>
#include <vector>
using namespace std;

int N, M;
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

bool Check(int x, int y, vector<string> board) {
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) return false;
        if (board[x][y] != board[nx][ny]) return false;
    }
    return true;
}

int delete_block(vector<pair<int, int>> V, vector<string> &board) {
    int cnt = 0;
    for (int i = 0; i < V.size(); i++) {
        int x = V[i].first;
        int y = V[i].second;
        if (board[x][y] != '.') {
            board[x][y] = '.';
            cnt++;
        }

        for (int j = 0; j < 3; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (board[nx][ny] != '.') {
                cnt++;
                board[nx][ny] = '.';
            }
        }
    }
    return cnt;
}

void arrange_map(vector<string> &board) {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '.') continue;

            int nx = i + 1;
            while (nx < N && board[nx][j] == '.') nx++;
            nx--;
            if (nx != i) {
                board[nx][j] = board[i][j];
                board[i][j] = '.';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    N = m;
    M = n;
    int answer = 0;
    bool flag = true;

    while (flag == true) {
        flag = false;
        vector<pair<int, int>> V;
        vector<vector<bool>> Visit(N, vector<bool>(M, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == '.') continue;
                if (Check(i, j, board) == true) {
                    V.push_back(make_pair(i, j));
                    flag = true;
                }
            }
        }

        if (flag == true) {
            answer = answer + delete_block(V, board);
            arrange_map(board);
        }
    }
    return answer;
}
