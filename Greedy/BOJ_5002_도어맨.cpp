#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int x, len, cnt, cnt_w, cnt_m, diff;
string s;
vector <char> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x;
	cin >> s;
	len = s.length();

	for (int i = 0; i < len; i++) {
		v.push_back(s[i]);
	}
	int flag = 0;

	while (true) {
		diff = abs(cnt_m - cnt_w);
		if (diff > x) flag = 1;
		if (v.empty()) break;
		// 맨 처음이거나 입장한 남자/여자 수가 같은 경우
		if (cnt_w == cnt_m) {
			// 각각 여자/남자 카운트++
			if (v[0] == 'W') cnt_w++;
			else cnt_m++;
			v.erase(v.begin());
		}
		else {
			// 이 부분 위와 중복: 코드 리팩토링 필요
			diff = abs(cnt_m - cnt_w);
			if (diff > x) {
				// 이 때는 넣었는데 이미 초과한 경우로, 
				// 이미 넣은 걸 하나 빼주는 동작이 필요: flag=1 을 반환하자.
				flag = 1;
				break;
			}

			// 여자가 더 많을 땐, 남자가 있으면 남자 넣어주기
			if (cnt_w > cnt_m) {
				if (v[0] == 'M') {
					v.erase(v.begin());
					cnt_m++;
				}
				else if (v.size() > 1 && v[1] == 'M') {
					v.erase(v.begin() + 1);
					cnt_m++;
				}
				else {
					v.erase(v.begin());
					cnt_w++;
				}
			}
			// 남자 인원이 더 많을 땐, 반대로 여자를 우선적으로 넣어주기
			else {
				if (v[0] == 'W') {
					v.erase(v.begin());
					cnt_w++;
				}
				else if (v.size() > 1 && v[1] == 'W') {
					v.erase(v.begin() + 1);
					cnt_w++;
				}
				else {
					v.erase(v.begin());
					cnt_m++;
				}
			}
		}
	}

	if (flag == 1) {
		cout << cnt_w + cnt_m - 1;
	}
	else {
		cout << cnt_w + cnt_m;
	}

	return 0;
}