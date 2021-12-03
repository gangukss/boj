#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int e, s, m, ans = 1;
	cin >> e >> s >> m;
	for (int i = 1, j = 1, k = 1; ; ++i, ++j, ++k, ++ans) {
		if (i > 15)
			i = 1;
		if (j > 28)
			j = 1;
		if (k > 19)
			k = 1;
		if (e == i && s == j && m == k)
			break ;
	}
	cout << ans;
}