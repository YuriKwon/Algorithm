#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s, t;
int n;

// 투 포인터 문제. 어려움
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		s += ch;
	}


	int left = 0;
	int right = n - 1;

	// 투 포인터, 양끝에서 가운데로
	while (left <= right) {
		if (s[left] == s[right]) {
			int tl = left + 1;
			int tr = right - 1;
			bool flag = false;

			while (tl <= tr) {
				if (s[tl] < s[tr]) {
					t += s[left++];
					flag = true;
					break;
				}

				else if (s[tl] > s[tr]) {
					t += s[right--];
					flag = true;
					break;
				}

				else {
					tl++;
					tr--;
				}
			}

			if (!flag) {
				t += s[left++];
			}

		}

		else if (s[left] < s[right]) {
			t += s[left++];
		}

		else {
			t += s[right--];
		}
	}

	for (int i = 0; i < t.size(); i++) {
		if (i != 0 && i % 80 == 0) cout << endl;
		cout << t[i];
	}

	return 0;

}
