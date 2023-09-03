#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

char path[8];
int visited[8];
int len;
set<int> sosu;
set<int> isChecked; // 체크한 적 있는 애들

bool isSosu(int num) {
    if (num == 0 || num == 1) return false;

    int isDevidedCnt = 0; // 나눠떨어진 경우 증가
    for (int i=2; i<num; i++) {
        if (num % i == 0) isDevidedCnt++;
    }
    return (isDevidedCnt == 0) ? true : false;
}

void DFS(int level, string numbers) {
    if (level != 0) {
        string num = "";
        for (int i=0; i<level; i++) {
            num += path[i];
        }

        int targetNum = stoi(num);

        // 이미 검사한적 있으면 다시 검사하지 않아야 시간초과 발생하지 않음
        if (isChecked.count(targetNum) == 0) {
            isChecked.insert(targetNum);
            if (isSosu(stoi(num))) {
                sosu.insert(stoi(num));
            }
        }

    }

    if (level == len) {
        return;
    }


    for (int i=0; i<len; i++) {
        if (visited[i] == 1) continue;
        path[level] = numbers[i];
        visited[i] = 1;
        DFS(level+1, numbers);
        visited[i] = 0;
    }

}

int solution(string numbers) {
    len = numbers.length();
    DFS(0, numbers);
    return sosu.size();
}
