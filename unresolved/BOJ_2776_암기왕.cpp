// 시간초과
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, num;
int dat[1000001];
vector<int> note1;
vector<int> note2;
vector<int> seq;

int main() {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> t;
	for (int i=0; i<t; i++) {
		// 수첩1
		cin >> n;
		for (int j=0; j<n; j++) {
			// 점수 입력
			cin >> num;
			note1.push_back(num);
		}
		sort(note1.begin(), note1.end()); // 정렬

		// 수첩2
		cin >> m;
		for (int j=0; j<m; j++) {
			// 점수 입력
			cin >> num;
			note2.push_back(num);
			seq.push_back(num); // 입력순 저장
		}
		sort(note2.begin(), note2.end()); // 정렬

		int startIdx = 0;
		int endIdx = n;
		int flag = 0;
		for (int j=0; j<m; j++) {
			int val = note2[j];
			// 이분 탐색
			while(startIdx <= endIdx) {
				int tar = note1[(startIdx + endIdx)/2];
				if (val == tar) {
					flag = 1;
					break;
				} else if (val < tar) {
					endIdx = (startIdx + endIdx)/2;
				} else {
					startIdx = (startIdx + endIdx)/2;
				}
				if (flag) dat[j] = 1;
				else dat[j] = 0;
			}
		}

		for (int j=0; j<m; j++) {
			cout << dat[seq[j]] << '\n';
		}
	}
	return 0;
}
