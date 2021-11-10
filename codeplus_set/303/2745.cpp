#include <iostream>
#include <cmath>
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

	string n;
	int b, ans = 0;
	cin >> n >> b;
	for (size_t i = 0; i < n.size(); ++i) {
		int j = 0;
		while (n[i] != num[j])
			++j;
		ans += j * pow(b, (n.size() - 1 - i));
	}
	cout << ans;
}
