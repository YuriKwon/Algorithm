#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int checkCondition(string friends, string condition) {
    char first = condition[0];
    char second = condition[2];
    char mark = condition[3];
    int distance = condition[4] - '0';
    // cout << friends.find(first) << '\n';
    // int gap = 1;
    int gap = abs((int)(friends.find(first) - friends.find(second))) - 1;

    if (mark == '=') {
        if (gap != distance) return 0;
    } else if (mark == '>') {
        if (gap <= distance) return 0;
    } else if (mark == '<') {
        if (gap >= distance) return 0;
    }
    return 1;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do {
        // friends 문자열이 순열로 (쫙 나옴)
        // 이 중에서 주어진 조건을 전부 만족하는 것을 찾아야 함.
        int flag = 0;
        // 현재 문자열(friends)이 주어진 조건을 만족하는지 검사.
        for (string condition : data) { // condition: 조건
            int val = checkCondition(friends, condition);
            // 한 조건이라도 만족하지 않는 문자열은 PASS (while 문 밖으로)
            if (val == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
        else answer++;
    } while(next_permutation(friends.begin(), friends.end()));

    return answer;
}
