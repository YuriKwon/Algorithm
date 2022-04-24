// next_permutation 함수 배움 (<algorithm> 헤더 파일)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


bool isRight(char c, int diff, int num){
    if(c == '='){
        return diff == num;
    } else if(c == '>'){
        return diff > num;
    } else if(c == '<'){
        return diff < num;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do {
        bool flag = true;
        for(string text : data){
            char first = text[0];
            char second = text[2];
            char comp = text[3];
            int num = text[4] - '0';
            int diff = friends.find(first) - friends.find(second);
			int dis = abs(diff) - 1;

            if(isRight(comp, dis, num)) continue;
            flag = false;
            break;
        }
        if(flag) answer++;
    } while(next_permutation(friends.begin(), friends.end()));

    return answer;
}
