#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n, cnt;
int main() {
	cin >> n;

	for (int i=0; i<n; i++) {
		stack<char> st;
		string str;

		cin >> str;
		int len = str.length();

		if (len % 2 != 0) continue;

		for (int j=0; j<len; j++) {
			if (st.size() == 0) {
				st.push(str[j]);
			} else {
				if (str[j] == st.top()) {
					st.pop();
				} else {
					st.push(str[j]);
				}
			}
		}

		if (st.size() == 0) cnt++;
	}
  
	cout << cnt;
	return 0;
}
