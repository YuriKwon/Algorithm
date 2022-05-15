#include <bits/stdc++.h>
using namespace std;

int main() {
	while(true) {
		string s;
		getline(cin, s);
		if (s == ".") break;
		int len = s.length();
		stack <char> st;
		int flag = 0;

		for (int i=0; i<len; i++) {
			char ch = s[i];
			if (ch == '(' || ch == '[') {
				st.push(ch);
			} else if (ch == ')') {
				if (st.empty()) {
					flag = 1; // no
					break;
				} else if (st.top() == '(') {
					st.pop();
				} else { // else 를 안써서 틀렸었음( 반례: [)] )
					flag = 1;
					break;
				}
			} else if (ch == ']') {
				if (st.empty()) {
					flag = 1; // no
					break;
				} else if (st.top() == '[') {
					st.pop();
				} else {
					flag = 1;
					break;
				}
			}
		}
		if (st.size() == 0 && flag == 0) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
