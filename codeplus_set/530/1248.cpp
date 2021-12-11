#include <iostream>
using namespace std;

int n, ans[10];
char input[10][10];
bool visit[21], flag;

bool isValid(int row, int col) {
	if (row > col)
		return true;
	int sum = 0;
	for (int i = row; i <= col; ++i)
		sum += ans[i];
	if (input[row][col] == '+' && sum > 0)
		return isValid(row + 1, col);
	else if (input[row][col] == '-' && sum < 0)
		return isValid(row + 1, col);
	else if (input[row][col] == '0' && sum == 0)
		return isValid(row + 1, col);
	return false;
}

void dfs(int col) {
	if (flag)
		return ;
	if (col >= n) {
		for (int i = 0; i < n; ++i)
			cout << ans[i] << " ";
		flag = 1;
		return ;
	}
	for (int num = -10; num <= 10; ++num) {
		ans[col] = num;
		if (isValid(0, col))
			dfs(col + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			cin >> input[i][j];
	dfs(0);
}
