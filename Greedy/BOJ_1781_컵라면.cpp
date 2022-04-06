#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq; // 컵라면 수 저장, 최소힙  

struct Node {
    int deadline;
    long long int cup;
};
Node arr[200000];
long long int sum; // 받을 수 있는 컵라면 수


int compare(Node a, Node b) {
    if (a.deadline < b.deadline) return 1;
    else if (a.deadline == b.deadline) {
        if (a.cup < b.cup) return 1;
        else return 0;
    }
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].deadline >> arr[i].cup;
    }
    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++) {
        pq.push(arr[i].cup);
        if (pq.size() > arr[i].deadline) {
            pq.pop();
        }
    }
    int size = pq.size();
    for (int i = 0; i < size; i++) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}