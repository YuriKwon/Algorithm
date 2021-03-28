#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

//front, back 구분이 매우 중요했던 문제

void check(string s, int len) {
    deque <char> st;
    deque <char> temp;
    for (int i = 0; i < len; i++) {
        if (s[i] == '-') {
            if(!st.empty()) st.pop_back();
        }
        else if (s[i] == '<') {
            //temp에 넣어줄때 뒤로 넣어주면 안됨, front로 넣어줘야 제대로 출력됨.
            //반례 : 1, j><>-<u->xb<<a 정상출력 : axb
            if (!st.empty()) {
                temp.push_front(st.back());
                st.pop_back();
            }
        }
        else if (s[i] == '>') {
            if (!temp.empty()) {
                st.push_back(temp.front());
                temp.pop_front();
            }
        }
        else { //문자
            st.push_back(s[i]);
        }
    }
    int size = st.size();
    for (int i = 0; i < size; i++) {
        //출력때문에 스택에서 덱으로 바꿈
        cout << st.front();
        st.pop_front();
    }
    // 여기 안넣어주면 1, ab<- 입력시 b 출력이 안됨
    //else 로 빼면, 1, a><><b 입력시 b만 나와버림
    int size2 = temp.size();
    for (int i = 0; i < size2; i++) {
        cout << temp.front();
        temp.pop_front();
    }
    cout << '\n';
}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int len = s.length();
        check(s, len);
    }


    return 0;
}

