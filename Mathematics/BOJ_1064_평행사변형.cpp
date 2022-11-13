#include <bits/stdc++.h>
using namespace std;


double x_1, x_2, x_3, y_1, y_2, y_3;
double incline1, incline2; // incline: 기울기

double getLength(double a, double b, double c, double d) {
	return sqrt((a-b) * (a-b) + (c-d)*(c-d));
}

int main() {
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;

	incline1 = abs(y_2 - y_1)/abs(x_2 - x_1);
	incline2 = abs(y_2 - y_3)/abs(x_2 - x_3);

	if (incline1 == incline2) {
		cout << -1;
		return 0;
	}

	double abLen = getLength(x_1, x_2, y_1, y_2);
	double bcLen = getLength(x_3, x_2, y_3, y_2);
	double acLen = getLength(x_1, x_3, y_1, y_3);

	double circum1 = (abLen + acLen) * 2; // A가 중간지점인 경우
	double circum2 = (abLen + bcLen) * 2; // B가 중간지점인 경우
	double circum3 = (bcLen + acLen) * 2; // C가 중간지점인 경우


	printf("%.16f",max({circum1, circum2, circum3}) - min({circum1, circum2, circum3}));

	return 0;
}
