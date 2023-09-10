#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int numberCnt;
int visited[100001];
int path[100001];
string maxNumber = "";
vector<int> numbers;

vector<string> v;

int compare(string a, string b) {
    // 두 문자열을 연결한 결과가 더 큰 순서대로 정렬
    return a + b > b + a;
}

string solution(vector<int> inputNumbers) {
    numberCnt = inputNumbers.size();
    for (int i=0; i<numberCnt; i++) {
        v.push_back(to_string(inputNumbers[i]));
    }
    sort(v.begin(), v.end(), compare);

    for (int i=0; i<numberCnt; i++) {
        maxNumber += v[i];
    }

   // 만약 결과가 0으로 시작한다면 "0"을 반환
    if (maxNumber[0] == '0') {
        return "0";
    }

    return maxNumber;
}
