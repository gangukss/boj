#include <iostream>
#include <vector>
#include <array>
#define M 1000000
using namespace std;

array<int, M> input, ans;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> input[i];
	for (int i = n - 1; i >= 0; --i) {
		while (!v.empty() && v.back() <= input[i])
			v.pop_back();
		if (v.empty())
			ans[i] = -1;
		else
			ans[i] = v.back();
		v.emplace_back(input[i]);
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
}
