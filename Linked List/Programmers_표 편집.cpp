#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int num;
    Node* prev;
    Node* next;
};

string solution(int n, int k, vector<string> cmd) {
    int current = k;
    stack<int> st; // 최근에 삭제된 행을 저장하기 위한 스택(Z에 필요)
    vector<bool> active(n, true); // 비교(O, X)
    // 양방향 링크드 리스트(표) 생성
    vector <Node *> table(n);
    for (int i=0; i<n; i++) {
        table[i] = new Node {i, NULL, NULL};
    }

    // 연결
    table[0]-> next = table[1];
    table[n-1]->prev =table[n-2];
    for (int i=1; i<n-1; i++) {
        table[i]->next = table[i+1];
        table[i]->prev = table[i-1];
    }


    int len = cmd.size();
    int cnt = 0; // 각 동작 횟수
    for (int i=0; i<len; i++) {
        char cmdLine = cmd[i][0]; // 명령어(알파벳)

        if (cmdLine == 'U') {
            // 의문: 여기서 cnt = (int)(cmd[i][2]) - 48; 로 하면 틀리는 이유가 뭘까?
            cnt = stoi(cmd[i].substr(2));
            for (int j=0; j<cnt; j++) {
                current = table[current]->prev->num;
            }
        }
        else if (cmdLine == 'D') {
            cnt = stoi(cmd[i].substr(2));
            for (int j=0; j<cnt; j++) {
                current = table[current]->next->num;
            }
        }
        else if (cmdLine == 'C') {
            st.push(table[current]->num);
            active[table[current]->num] = false;

            if (table[current]->prev != NULL) {
                table[current]->prev->next = table[current]->next;
            }
            if (table[current]->next == NULL) {
                current = table[current]->prev->num;
            }
            else {
                table[current]->next->prev = table[current]->prev;
                current = table[current]->next->num;
            }
        }
        else if (cmdLine == 'Z') {
            // 복구: 스택 top에 있는 행을 true로
            int top = st.top();
            if (table[top]->prev != NULL) {
                table[top]->prev->next = table[top];
            }
            if (table[top]->next != NULL) {
                table[top]->next->prev = table[top];
            }

            active[top] = true;
            st.pop();
        }
    }

    string answer = "";
    for (int i=0; i< active.size(); i++) {
        if (active[i] == true) answer += "O";
        else answer += "X";
    }
    return answer;
}
