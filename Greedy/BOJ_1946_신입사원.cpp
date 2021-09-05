#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
struct Node {
	int docu_rank; // 서류 순위
	int int_rank; // 면접 순위
};
Node applicant[100001];
int highest_int_rank = 100002;

int compare(Node A, Node B) {
	return A.docu_rank < B.docu_rank;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		int cnt = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> applicant[j].docu_rank >> applicant[j].int_rank;
		}
		sort(applicant, applicant + n, compare); // 서류 기준 오름차순 정렬
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				cnt++;
				highest_int_rank = applicant[j].int_rank; // 면접 최고 순위 갱신
			}
			else {
				if (applicant[j].int_rank < highest_int_rank) {
					cnt++;
					highest_int_rank = applicant[j].int_rank; // 면접 최고 순위 갱신
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}