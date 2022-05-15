#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> arr;
string s;
int n;

int getSum(string s) {
	int len = s.length();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '1' && s[i] <= '9') {
			sum += s[i] - '0';
		}
	}
	return sum;
}

int compare(string a, string b) {
	if (a.length() < b.length()) return 1;
	else if (a.length() > b.length()) return 0;
	else {
		int sumA = getSum(a);
		int sumB = getSum(b);
		if (sumA != sumB) return sumA < sumB;
		else return a < b;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
