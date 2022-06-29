// Hash 문제인데 Sort로 풂..
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int len = participant.size();
    int flag = 0;
    // participant에 있는 값을 map에 다~ 넣고, completion에 있는 값을 map에 다~ 뺐는데.. 메모리 초과로 실패.
    // completion개수만큼만 비교(참조 에러 방지를 위해..)
    for (int i=0; i<len-1; i++) {
        if (participant[i] != completion[i]) {
            // 다르면, 그 때의 participant가 완주를 못한 사람
            answer = participant[i];
            flag = 1;
            break;
        }
    }

    // for문에서 못찾은 경우, 완주X 선수가 participant 배열의 맨 뒤 사람이라는 뜻
    if (flag == 0) {
        answer = participant.back();
    }

    return answer;
}
