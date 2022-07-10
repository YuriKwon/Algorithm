#include<iostream>
#include<string>
using namespace std;

string a,b;
int cnt;
int mini = 50;

int main(){
    cin >> a >> b;
	int len1 = a.length();
	int len2 = b.length();

	for (int i = 0; i <= len2 - len1; i++) {
		cnt = 0;
		for (int j = 0; j < len1; j++) {
			if (a[j] != b[i+j]) cnt++;
		}
		mini = (mini >= cnt) ? cnt : mini;
	}
	cout << mini << '\n';
}
