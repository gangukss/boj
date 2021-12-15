#include <iostream>
#include <string>
using namespace std;

int input[4][4];
int n, m, ans;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j)
			input[i][j] = s[j] - '0';
	}
	for (int bitset = 0; bitset < (1 << (n * m)); ++bitset) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int cur = 0;
			for (int j = 0; j < m; ++j) {
				int k = i * m + j;
				if ((bitset & (1 << k)) == 0) {
					cur = cur * 10 + input[i][j];
				} else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		for (int j = 0; j < m; ++j) {
			int cur = 0;
			for (int i = 0; i < n; ++i) {
				int k = i * m + j;
				if ((bitset & (1 << k)) != 0) {
					cur = cur * 10 + input[i][j];
				} else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ans = max(ans, sum);
	}
	cout << ans;
}
