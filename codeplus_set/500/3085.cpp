#include <iostream>
using namespace std;

int n, ans;
string input[50];

void checkHorizonLine(int i) {
	int cnt = 1;
	for (int idx = 1; idx < n; ++idx) {
		if (input[i][idx] == input[i][idx - 1])
			++cnt;
		else
			cnt = 1;
		ans = max(ans, cnt);
	}
}

void checkVerticalLine(int j) {
	int cnt = 1;
	for (int idx = 1; idx < n; ++idx) {
		if (input[idx][j] == input[idx - 1][j])
			++cnt;
		else
			cnt = 1;
		ans = max(ans, cnt);
	}
}

void checkRight(int i, int j) {
	if (j >= n - 1)
		return ;
	char tmp = input[i][j];
	input[i][j] = input[i][j + 1];
	input[i][j + 1] = tmp;
	checkHorizonLine(i);
	checkVerticalLine(j);
	checkVerticalLine(j + 1);
	input[i][j + 1] = input[i][j];
	input[i][j] = tmp;
}

void checkBottom(int i, int j) {
	if (i >= n - 1)
		return ;
	char tmp = input[i][j];
	input[i][j] = input[i + 1][j];
	input[i + 1][j] = tmp;
	checkHorizonLine(i);
	checkHorizonLine(i + 1);
	checkVerticalLine(j);
	input[i + 1][j] = input[i][j];
	input[i][j] = tmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			checkRight(i, j);
			checkBottom(i, j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			checkHorizonLine(i);
			checkVerticalLine(j);
		}
	}
	cout << ans;
}