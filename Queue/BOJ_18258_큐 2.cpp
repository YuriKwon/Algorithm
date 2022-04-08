#include <bits/stdc++.h>
using namespace std;

int main() {
    // 처음에 시간초과난 이유: 밑의 세줄을 안써서
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    
    queue<int> q;
    int n;
    cin >> n;

    string s;
    int num;
    for (int i=0; i<n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> num;
            q.push(num);
        } else if (s == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (s == "size") {
            cout << q.size() << "\n";
        } else if (s == "empty") {
            if (q.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (s == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (s == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << "\n";
            }
        }
    }
    return 0;
}
