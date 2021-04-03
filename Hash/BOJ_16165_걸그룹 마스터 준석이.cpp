#include <iostream>
#include <unordered_map>
#include <string>
#include <queue> // 사전순 정렬을 위한 pq
using namespace std;

unordered_map<string, string> um;
priority_queue<string, vector<string>, greater<string>> pq;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) { // um에 정보 넣기
		string team; // 팀 이름
		int num; // 그룹 인원 수
		cin >> team;
		cin >> num;
		for (int j = 0; j < num; j++) {
			string name; // 멤버 이름
			cin >> name;
			um[name] = team;
		}
	}
	
	int debug;

	for (int i = 0; i < m; i++) { // 퀴즈
		string quiz;
		int quizType;
		cin >> quiz;
		cin >> quizType;
		if (quizType == 0) {
			for (auto i = um.begin(); i != um.end(); ++i) {
				if (i->second == quiz) {
					pq.push(i->first);
				}
			}
			while (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else { //quizType == 1
			cout << um[quiz] << '\n';
		}
	}

	return 0;
}

