#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, T;
int ans;
vector<pair<string, int>> v;
string s1, s2;

int main() {
	cin >> T;

	while (T--) {
		ans = 1;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> s1 >> s2;

			if (v.size() == 0) {
				v.push_back(pair(s2, 1));
				continue;
			}

			for (int j = 0; j < (int)v.size(); j++) {
				if (s2 == v[j].first) {
					v[j].second++; // 개수 체크
					break;
				}
				if (j == (int)v.size() - 1) v.push_back(pair(s2, 0)); // vector에 있지않은 원소라면 추가.
			}
		}
		for (int k = 0; k < (int)v.size(); k++) {
			ans *= (v[k].second + 1);
        }
		cout << ans - 1 << "\n";
		v.clear();
	}
}
