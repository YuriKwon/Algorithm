#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string formula = "";
    cin >> formula;
    stack<string> st;

    for (char c : formula) {
        string s = "";
        s += c;
        if (s == "(" || s == "H" || s == "C" || s == "O") {
            st.push(s);
        } else if (s == ")") {
            int num = 0;
            while (!st.empty() && st.top() != "(") {
                if (st.top() == "H") {
                    num += 1;
                } else if (st.top() == "C") {
                    num += 12;
                } else if (st.top() == "O") {
                    num += 16;
                } else {
                    num += stoi(st.top());
                }
                st.pop();
            }
            st.pop();
            st.push(to_string(num));
        } else if (s >= "1" && s <= "9") {
            int tmp = 0;
            if (st.top() == "H") {
                tmp = 1;
            } else if (st.top() == "C") {
                tmp = 12;
            } else if (st.top() == "O") {
                tmp = 16;
            } else {
                tmp = stoi(st.top());
            }
            st.pop();
            st.push(to_string(tmp * stoi(s)));
        }
    }

    int sum = 0;
    while (!st.empty()) {
        if (st.top() == "H") {
            sum += 1;
        } else if (st.top() == "C") {
            sum += 12;
        } else if (st.top() == "O") {
            sum += 16;
        } else {
            sum += stoi(st.top());
        }
        st.pop();
    }
    cout << sum;
    return 0;
}
