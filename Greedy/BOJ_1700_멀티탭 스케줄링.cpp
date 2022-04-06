#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k, num;
int used[101]; // 그 기구가 이미 사용중인지 검사 (현재 꽂혀있는 애들)
int use_cnt; // 사용중인 플래그 개수
int unplug_sum; // 플러그 빼는 횟수

queue<int> q; // 기구 대기 목록
priority_queue<int, vector<int>, greater<int>> arr[101]; // 최소 힙(해당 기구의 등장 위치를 넣어주는 목적, top이 바로 다음 등장위치)

int getUnplug() {
    int maxIndex = 0;
    int maxFlag = 0;
    for (int i = 0; i < 100; i++) {
        if (used[i]) { // 해당 기구가 현재 꽂혀있을 때,
            // 앞으로 사용하지 않는 기구면 -> 바로 뽑아준다.
            if (arr[i].size() == 0) return i;
            // 앞으로 사용하는 기구라면, 다음에 꽂는 위치를 가져와서 그게 제일 큰 값인 기구를 리턴
            // = 다음에 등장하는 위치가 가장 나중인 것을 뽑아준다.
            arr[i].top(); // 다음에 꽂아줘야 할 위치
            if (arr[i].top() > maxIndex) {
                maxIndex = arr[i].top();
                maxFlag = i;
            }
        }
    }
    return maxFlag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> num;
        arr[num].push(i); // 각 기구의 위치를 넣어준다.
        q.push(num); // 기구 사용 대기열
    }

    // 돌아가면서 기구 꼽기
    // queue를 순환해야함
    while (!q.empty()) { // 공통 부분 코드 정리하면 더 좋을 듯.
        // 꽂을 대상이 이미 사용중인 기구라면?
        if (used[q.front()]) {
            arr[q.front()].pop(); // 그 기구의 다음 등장위치에서도 빼준다.
            q.pop(); // 대기열에서 빼주고
            continue;
        }
        // 꽂을 대상이 지금 사용중이지 않은 기구라면?
        else {
            // 콘센트가 비어있는 경우, 바로 꽂아준다.
            if (use_cnt < n) {
                used[q.front()] = 1;
                arr[q.front()].pop();
                q.pop();
                use_cnt++;
            }
            // 콘센트가 전부 사용중일 경우, 뽑아야 한다.
            else {
                // 현재 사용중인 플래그 중, 뽑을 플래그를 찾아 뽑는다.
                int deletePlug = getUnplug();
                used[deletePlug] = 0;
                unplug_sum++;
                // 큐의 맨앞에 있는 플래그를 꽂아준다.
                used[q.front()] = 1;
                arr[q.front()].pop();
                q.pop();
            }
        }
    }

    cout << unplug_sum;

    return 0;
}