#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/* 맨 처음 풀이: userId - userName 을 맵핑할 때 map 자료구조를 잘 몰라서
pair를 담는 vector에 넣어놓고 vector를 일일히 반복문으로 돌면서 일치하는 userId가
있는지 검사했었음 -> 시간초과 발생

그래서 map 자료구조로 변경 (map 자료구조 사용 시 key값으로 value를 빠르게 검색 및 수정 가능)
*/

struct Node {
	string command, userId;
};
queue<Node> q;
map<string, string> id_and_name;

string getName(string userId) {
	return id_and_name[userId];
}

vector<string> solution(vector<string> record) {
    int len = record.size(); // command count
    vector<string> answer;

	for (int i = 0; i < len; i++) {
		// 띄어쓰기 단위로 벡터에 넣어주기
		string line = record[i];
		istringstream ss(line);
		string word;
		vector<string> words;

		while (getline(ss, word, ' ')) {
			words.push_back(word);
		}

		if (words[0] == "Enter") {

			int flag = 0;

			if (id_and_name.find(words[1]) != id_and_name.end()) {
				id_and_name[words[1]] = words[2];
				flag = 1;
			}

			if (flag == 0) {

				id_and_name.insert(make_pair(words[1], words[2]));
			}
			q.push({ "E",  words[1]});
		}
		else if (words[0] == "Leave") {
			q.push({ "L",  words[1]});
		}
		else { // Change
			if (id_and_name.find(words[1]) != id_and_name.end()) {
				id_and_name[words[1]] = words[2];
			}
		}
		int dummy = 0;
	}

	while (!q.empty()) {
		string userId = q.front().userId;
		string userName = getName(userId);
		if (q.front().command == "E") {
            answer.push_back(userName + "님이 들어왔습니다.");
		}
		else {
            answer.push_back(userName + "님이 나갔습니다.");
		}
		q.pop();
	}

    return answer;
}
