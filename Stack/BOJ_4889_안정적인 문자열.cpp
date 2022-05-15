#include <bits/stdc++.h>
using namespace std;

    int num=1; // 출력을 위한 번호
    int cnt; // 연산횟수
    int left_bracket_cnt; // 스택 안에 들어있는 { 괄호 개수

    int main() {
	string s;
    stack <char> st;

	while(true) {
		getline(cin, s);
		// 문자열에 -가 포함되어 있으면 종료
		if (s.find('-') != string::npos) return 0;
		int len = s.length();
        for (int i=0; i<len; i++) {
            char ch = s[i];
            if (ch == '{') {
                st.push(ch);
            } else if (ch == '}') {
                if (st.empty()) {
                    st.push('{');
                    cnt++; // } -> { 바꿨으므로 연산횟수 증가
                } else if (st.top() == '{') {
                    st.pop();
                } else {
                    // 여기에 들어오는 경우가 없을 듯.
                    cout << "여기에 들어오면 출력\n";
                }
            }
        }

        while(!st.empty()) {
            char top = st.top();
            if (top == '{') left_bracket_cnt++;
            st.pop();
        }
        cnt += left_bracket_cnt/2;
        cout << num << ". " << cnt << "\n";
        cnt = 0;
        num++;
	}

	return 0;
}
