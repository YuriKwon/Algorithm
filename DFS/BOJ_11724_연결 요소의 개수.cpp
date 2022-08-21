#include <iostream>
#include <stack>
using namespace std;

int n, m, cnt;
int arr[1001][1001];
int visited[1001];

void dfs(int num) {
    visited[num] = 1;

    for (int i=1; i<=n; i++) {
        if (arr[num][i] == 1 && visited[i] != 1) {
            dfs(i);
        }
    }
}

int main() {
    // input
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    // dfs
    for (int i=1; i<=n; i++) {
        if (visited[i] != 1) {
                cnt++;
                dfs(i);
        }
    }

    // output
    cout << cnt;
    return 0;
}

// 공부할 때 참고 블로그: https://rolypolytoy.tistory.com/35
