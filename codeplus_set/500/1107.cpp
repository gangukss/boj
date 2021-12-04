#include <iostream>
using namespace std;
const int MAX = 1e6;

int n, m, ans = MAX, cur = 100, flag;
bool wrongButton[11];

bool isPossible(int num) {
	for (; num / 10; num /= 10)
		if (wrongButton[num % 10])
			return 0;
	if (wrongButton[num])
		return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		wrongButton[tmp] = 1;
	}
	for (int i = 0; n + i <= MAX; ++i) {
		if (isPossible(n + i)) {
			int tmp = 0;
			for (int target = n + i; target / 10; target /= 10)
				++tmp;
			++tmp;
			ans = min(tmp, ans);
			cur = n + i;
			flag = 1;
		}
		if (n - i >= 0 && isPossible(n - i)) {
			int tmp = 0;
			for (int target = n - i; target / 10; target /= 10)
				++tmp;
			++tmp;
			ans = min(tmp, ans);
			cur = n - i;
			flag = 1;
		}
		if (flag)
			break ;
	}
	ans += max(cur - n, n - cur);
	ans = min(ans, max(n - 100, 100 - n));
	cout << ans;
}