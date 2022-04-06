#include <iostream>
#include <algorithm>
using namespace std;

int n, t, cnt;
int arr[101][101];
int visited[101]; 

void run(int now) {
    cnt++;
    for (int i = 1; i <= n; i++) {
        if (arr[now][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            run(i);
        }
    }
}
int main() {
    cin >> n >> t;
    int n1, n2;

    for (int i = 0; i < t; i++) {
        cin >> n1 >> n2;
        arr[n1][n2] = 1;
        // 노드간 방향이 없으므로, 이렇게 양방향에 체크해줘야 했음에 주의하자.
        arr[n2][n1] = 1; // 방향이 없는 그래프이므로 반대 방향으로도 체크해줘야 함.. (틀린 이유)
    }

    visited[1] = 1; // 맨 처음 노드는 당연히 방문 -> set
    run(1); // 1번부터 DFS 탐색 시작
    cout << cnt - 1;
    return 0;
}
