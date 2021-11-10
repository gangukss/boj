#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char num[36] = {'0', '1', '2', '3', '4', '5',
				'6', '7', '8', '9', 'A',
				'B', 'C', 'D', 'E', 'F',
				'G', 'H', 'I', 'J', 'K',
				'L', 'M', 'N', 'O', 'P',
				'Q', 'R', 'S', 'T', 'U',
				'V', 'W', 'X', 'Y', 'Z'};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, b;
	vector<char> ans;
	cin >> n >> b;
	while (n) {
		ans.emplace_back(num[n % b]);
		n /= b;
	}
	reverse(ans.begin(), ans.end());
	for (size_t i = 0; i < ans.size(); ++i)
		cout << ans[i];

}
