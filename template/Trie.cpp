#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int ALPHABETS_CNT = 26;

int charToIdx(char ch) {
    return ch - 'a';
}

// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
    bool isEnd;
    TrieNode* children[ALPHABETS_CNT]; // 자손 노드들을 가리키는 포인터 목록
    // 고정 길이 배열 (알파벳 대문자라면, 길이 26으로 고정) -> 메모리 낭비 큼

    // 생성자
    TrieNode() : isEnd(false) {
        memset(children, 0, sizeof(children));
    }

    // 소멸자
    ~TrieNode() {
        for (int i=0; i<ALPHABETS_CNT; i++) {
            if (children[i]) delete children[i];
        }
    }

    void insert(const char* key) {
        if (*key == '\0') isEnd = true;
        else {
            int next = charToIdx(*key);
            if (children[next] == NULL) children[next] = new TrieNode();
            children[next] -> insert(key + 1);
        }
    }

    // 일부만 포함돼도 찾음(접두사 검색, 자동완성 기능에 필요한)
    bool find(const char* key) {
        if (*key == '\0') return true; // this 포인터: 멤버 함수가 호출된 객체의 주소를 가리키는 포인터
        int next = charToIdx(*key);
        if (children[next] == NULL) return false;
        return children[next] -> find(key + 1);
    }

    // 완전히 일치하는 경우만 찾음
    bool find2(const char* key) {
        if (*key == '\0' && isEnd) return true;
        if (*key == '\0' && !isEnd) return false;
        int next = charToIdx(*key);
        if (children[next] == NULL) return false;
        return children[next] -> find2(key + 1);
    }
};

int main() {
    vector <string> words = {"yuri", "zzang", "apple", "banana"};
    TrieNode root;
    for (string word : words) {
        const char* ptr = &word[0];
        root.insert(ptr);
    }

    cout << root.find("yu") << " " << root.find("yut") << " " << root.find("yur") << endl; // t f t
    cout << root.find2("yu") << " " << root.find2("yur") << " " << root.find2("yuri"); // f f t

    return 0;
}
