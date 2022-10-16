#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;

int charToIdx(char ch) {
    return ch - '0';
}

// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
    bool isEnd;
    TrieNode* children[10]; // 자손 노드들을 가리키는 포인터 목록
    // 고정 길이 배열 (알파벳 대문자라면, 길이 26으로 고정) -> 메모리 낭비 큼

    // 생성자
    TrieNode() : isEnd(false) {
        memset(children, 0, sizeof(children));
    }

    // 소멸자
    ~TrieNode() {
        for (int i=0; i<10; i++) {
            if (children[i]) delete children[i];
        }
    }

    void insert(const char* key) {
        if (*key == '\0') {
            isEnd = true;
        }
        else {
            int next = charToIdx(*key);
            if (children[next] == NULL) {
                children[next] = new TrieNode();
            }
            children[next] -> insert(key + 1);
        }
    }

    bool find(const char* key) {
        if (*key == NULL) return true;
        if (isEnd) return false;
        int next = charToIdx(*key);
        return children[next] -> find(key + 1);
    }
};


int main() {
    cin >> t;
    for (int i=0; i<t; i++) {
        bool isConsistList = true;
        vector <string> v;
        cin >> n;
        TrieNode root;
        for (int j=0; j<n; j++) {
            string num;
            cin >> num;
            v.push_back(num);
            const char* ptr = &num[0];
            root.insert(ptr);
        }
        for (string phoneNum : v) {
            const char* ptr = &phoneNum[0];
            if (root.find(ptr) == 0) {
                isConsistList = false;
                break;
            }
        }
        if (isConsistList) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

// 참고:  https://yabmoons.tistory.com/397
