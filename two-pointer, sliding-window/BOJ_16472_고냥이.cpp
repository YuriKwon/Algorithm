#include <iostream>
#include <string>
using namespace std;

//문자 나온 횟수 카운트를 위한 DAT
int DAT[200];
string s;

int main() {
	int n;
	cin >> n;
	cin >> s;
	int start = 0;
	int end = 0;
	int cnt = 1;

	int len = s.length();
	int max = 0;
	DAT[s[start]] = 1;
	int dif;
	//n=2인 문제를 기준으로 코드 이해를 위한 주석 작성
	while (1) {
		if (start == len - 1 && end == len - 1) break;
		if (end == len - 1) {
			if (cnt < n+1) {
				dif = end - start + 1;
				if (dif > max) max = dif;
			}
			DAT[s[start]]--;
			if (DAT[s[start]] == 0) {
				cnt--;
				start++;
			}
			else {
				start++;
			}
			continue;
		}
		if (cnt >= n+1) { //세 종류 이상의 문자가 나온 것
			DAT[s[start]]--; //앞에서부터 문자제거 (그 문자가 아예 사라질때까지 = cnt가 2 이하로 떨어질때까지)
			// (그 문자가 이제 아예 없다면, cnt를--)
			if (DAT[s[start]] == 0) {
				cnt--;
				start++;
			}
			//아직도 3문자가 있다면, 컨티뉴하고 다시 여기로 와서 앞문자 제거 작업 반복
			else {
				start++;
				continue;
			}
		}
		else {
			dif = end - start + 1;
			if (dif > max) max = dif;
			end++;
			if (DAT[s[end]] == 0) {
				DAT[s[end]]++;
				cnt++;
			}
			else {
				DAT[s[end]]++;
			}
		}
	}
	cout << max;
	return 0;
}